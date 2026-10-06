# 서유나 — Isaac Sim 6.0.1 WebRTC

이 폴더는 Isaac Sim을 헤드리스로 실행하고 Chromium 기반 WebRTC 웹 뷰어로 접속하는 독립 인스턴스입니다.

```bash
./manage.sh setup
./manage.sh start
```

`start`는 기본적으로 Isaac Sim을 WebRTC 모드로 자동 실행합니다. 대신 Isaac Lab 개발 컨테이너와 웹 뷰어를 띄운 뒤 셸에서 작업하려면 다음을 사용합니다.

```bash
./manage.sh remote
./manage.sh enter
```

`./manage.sh start --remote`는 `./manage.sh remote`와 같고, Isaac Lab 이미지를 빌드한 뒤 대기 상태의 Lab 컨테이너와 웹 뷰어를 실행합니다. 테스트 장면은 자동 실행하지 않습니다. `./manage.sh start --remote-sim`은 인자 없는 `./manage.sh start`와 같습니다.

## Isaac Lab 개발 컨테이너

Isaac Lab은 기존 WebRTC Isaac Sim과 패키지가 섞이지 않도록 별도 컨테이너로 실행합니다.

```bash
./manage.sh start --remote
./manage.sh enter
```

컨테이너 안에서는 Isaac Sim의 Python으로 스크립트를 실행합니다.

```bash
/isaac-sim/python.sh your_script.py
```

센서 config 파일은 실행 프로그램이 아니라 `CameraCfg`/`RayCasterCfg` 정의이므로, scene 스크립트에서 import해 사용합니다.

기본 접속 주소는 `http://192.168.50.166:8210`입니다. 서버 IP가 달라졌거나 Tailscale 주소를 광고하려면 다음처럼 실행합니다.

```bash
ISAACSIM_HOST=<접속 가능한 서버 IP> ./manage.sh start
```

주요 명령은 `./manage.sh status`, `./manage.sh logs`, `./manage.sh enter`, `./manage.sh stop`입니다. 공유 에셋은 컨테이너의 `/workspace/merged_asset`에 읽기/쓰기로 연결됩니다.

이 서비스에는 인증이나 암호화가 없으므로 신뢰할 수 있는 사설망에서만 사용하세요. 방화벽을 사용한다면 TCP `8210`, TCP `49100`, UDP `47998`을 허용해야 합니다. 하나의 Isaac Sim 스트림에는 클라이언트 하나만 접속할 수 있습니다.
