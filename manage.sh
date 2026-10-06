#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DATA_DIR="${SCRIPT_DIR}/.isaac-sim"
CONTAINER_UID=1234

cd "${SCRIPT_DIR}"

prepare_dirs() {
    local dirs=(
        cache/main
        cache/computecache
        config
        data
        logs
        pkg
        hub
    )
    local path

    for dir in "${dirs[@]}"; do
        mkdir -p "${DATA_DIR}/${dir}"
    done

    if command -v setfacl >/dev/null 2>&1; then
        # Do not recurse into uid-1234-owned cache contents on later starts.
        # Only bind-mount roots need host-side ACL setup.
        for path in "${DATA_DIR}" "${dirs[@]/#/${DATA_DIR}/}"; do
            if [[ -O "${path}" ]]; then
                setfacl -m \
                    "u:${CONTAINER_UID}:rwx,d:u:${CONTAINER_UID}:rwx,d:u:$(id -u):rwx,d:m:rwx" \
                    "${path}"
            fi
        done
    else
        for path in "${DATA_DIR}" "${dirs[@]/#/${DATA_DIR}/}"; do
            if [[ -O "${path}" ]]; then
                chmod a+rwx "${path}"
            fi
        done
    fi
}

detect_host_ip() {
    hostname -I 2>/dev/null | awk '{print $1}'
}

show_endpoints() {
    echo "Web viewer:     http://${ISAACSIM_HOST}:${WEB_VIEWER_PORT}"
    echo "WebRTC signal:  ${ISAACSIM_HOST}:${ISAACSIM_SIGNAL_PORT}/tcp"
    echo "WebRTC stream:  ${ISAACSIM_HOST}:${ISAACSIM_STREAM_PORT}/udp"
    echo "Shared assets:  /workspace/merged_asset (read/write)"
}

usage() {
    echo "Usage: $0 {setup|start [--remote|--remote-sim]|remote|stop|restart|status|logs|enter|url}"
    echo "  start, start --remote-sim  Start Isaac Sim with WebRTC (default)"
    echo "  start --remote, remote     Build Isaac Lab and start its idle container plus the web viewer"
    echo "  enter                      Open a shell in Isaac Lab (or Isaac Sim if Lab is stopped)"
    echo "Override the advertised address when needed: ISAACSIM_HOST=<ip> $0 start"
}

start_remote_sim() {
    prepare_dirs
    docker compose --profile lab stop isaac-lab
    docker compose up --build -d
    show_endpoints
}

start_remote() {
    prepare_dirs
    docker compose stop web-viewer isaac-sim
    docker compose --profile lab up --build -d --no-deps isaac-lab web-viewer
    echo "Isaac Lab container ready. Enter with: $0 enter"
    echo "No Isaac Lab test scene was started automatically."
    echo "Shared assets:  /workspace/merged_asset (read/write)"
}

start() {
    if (( $# > 1 )); then
        echo "[ERROR] Too many arguments for start." >&2
        usage
        exit 1
    fi

    case "${1:---remote-sim}" in
        --remote-sim)
            start_remote_sim
            ;;
        --remote)
            start_remote
            ;;
        *)
            echo "[ERROR] Unknown start mode: $1" >&2
            usage
            exit 1
            ;;
    esac
}

enter_container() {
    if docker compose --profile lab ps --status running --services isaac-lab | grep -qx "isaac-lab"; then
        docker compose --profile lab exec isaac-lab bash
    elif docker compose ps --status running --services isaac-sim | grep -qx "isaac-sim"; then
        docker compose exec isaac-sim bash
    else
        echo "[ERROR] Neither isaac-lab nor isaac-sim is running." >&2
        exit 1
    fi
}

CALLER_HOST="${ISAACSIM_HOST:-}"

set -a
# shellcheck disable=SC1091
source "${SCRIPT_DIR}/.env"
set +a

export ISAACSIM_HOST="${CALLER_HOST:-$(detect_host_ip)}"
if [[ -z "${ISAACSIM_HOST}" ]]; then
    echo "[ERROR] Could not detect a host IP. Set ISAACSIM_HOST explicitly." >&2
    exit 1
fi

case "${1:-}" in
    setup)
        prepare_dirs
        docker compose --profile lab config --quiet
        echo "Setup complete."
        show_endpoints
        ;;
    start)
        start "${@:2}"
        ;;
    remote)
        if (( $# > 1 )); then
            echo "[ERROR] remote does not accept arguments." >&2
            usage
            exit 1
        fi
        start_remote
        ;;
    stop)
        docker compose --profile lab down
        ;;
    restart)
        prepare_dirs
        docker compose --profile lab down
        docker compose up --build -d
        show_endpoints
        ;;
    status)
        docker compose --profile lab ps
        show_endpoints
        ;;
    logs)
        docker compose --profile lab logs -f "${@:2}"
        ;;
    enter)
        enter_container
        ;;
    url)
        show_endpoints
        ;;
    *)
        usage
        exit 1
        ;;
esac
