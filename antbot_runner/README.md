# Antbot Runner

Antbot 로봇 정의를 사용해 CUDA 시뮬레이션과 ROS 2 통신을 실행하는 패키지다.

~~~text
antbot_runner/
├── run_antbot.py             실행, 씬 구성, 센서 로그, ROS context 생명주기
├── action_graph.py           /clock과 /odom Action Graph
├── environment.py            .env, WebRTC, ROS 2/Zenoh 환경 설정
├── ros2/
│   ├── publisher.py          /joint_states와 전체 센서 발행
│   └── subscriber.py         joint command와 선택적 센서 입력 subscriber
├── ros2_config/              Zenoh session 설정
└── ros2_ws/                  gaemi_interfaces 메시지 workspace
~~~

## ROS 메시지 빌드

ros2_ws를 처음 구성하거나 메시지 정의를 변경했을 때 실행한다.

~~~bash
cd /workspace/antbot_runner/ros2_ws
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --cmake-args -DPython3_EXECUTABLE=/usr/bin/python3
~~~

## 실행

isaac-lab 컨테이너의 /workspace에서 실행한다.

Dockerfile이 변경되었으므로 최초 1회는 이미지를 다시 빌드한다.

~~~bash
docker compose --profile lab build isaac-lab
~~~

~~~bash
export LD_LIBRARY_PATH=/opt/ros/jazzy/opt/zenoh_cpp_vendor/lib:/opt/ros/jazzy/lib/x86_64-linux-gnu:/opt/ros/jazzy/lib:/workspace/antbot_runner/ros2_ws/install/gaemi_interfaces/lib:/isaac-sim/exts/isaacsim.ros2.core/jazzy/lib:$LD_LIBRARY_PATH
/isaac-sim/python.sh antbot_runner/run_antbot.py
~~~

LiDAR ray와 hit marker가 필요할 때만 --debug-vis를 추가한다.

`run_antbot.py`는 동일한 WebRTC 포트를 사용하는 인스턴스가 이미 있으면
Kit을 시작하지 않고 오류로 종료한다. WebRTC 스트림은 브라우저 탭 하나만
연결해야 한다.

`run_antbot.py`는 AppLauncher의 기본 Isaac Lab rendering experience를 사용하고,
WebRTC 설정은 실행 인자로 전달한다.

`NVST_R_BUSY`나 검은 뷰포트가 보이면 실행 중인 `run_antbot.py`를 `Ctrl+C`로
종료하고 Web Viewer 탭을 모두 닫은 뒤 다시 실행한다. 스크립트가 중복
실행 중인지 여부는 다음과 같이 확인한다.

~~~bash
pgrep -af 'python.*antbot_runner/run_antbot.py'
~~~

## 고정 구성

- 물리 장치: cuda:0
- 카메라: back, front, left, right, front_depth
- 2D LiDAR: front, back
- 3D LiDAR: main
- Action Graph: /clock, /odom
- Publisher: /joint_states와 전체 센서 토픽
- Subscriber: 실행 시 /joint_command만 활성화
- ROS middleware: `rmw_zenoh_cpp` (Fast DDS 설정은 사용하지 않음)
- Zenoh router: `tcp/localhost:7447` (`gaemi-zenoh-router`)
- Optional SensorSubscriber: 카메라·LiDAR 7개 토픽을 필요할 때만 활성화

publisher와 subscriber는 하나의 ROS node/context를 공유하지만 서로의 내부
상태를 소유하지 않는다. run_antbot.py는 JointCommandSubscriber만 생성한다.
SensorSubscriber는 runner가 센서 메시지를 직접 소비해야 하는 경우에만 별도로
생성한다. 실행 루프 순서는 command spin, CUDA target 적용, physics step,
sensor와 joint-state 발행 순서다.

센서를 켜거나 끄는 YAML, CLI, selection API는 없다.
ROS CLI 셸은 시뮬레이터와 같은 ROS_DOMAIN_ID를 사용해야 한다.

외부 ROS 2 터미널도 같은 middleware를 사용해야 한다.

~~~bash
source /opt/ros/jazzy/setup.bash
export RMW_IMPLEMENTATION=rmw_zenoh_cpp
export ROS_DOMAIN_ID=30
ros2 topic list
~~~

`rmw_zenoh_cpp`는 Isaac Lab 이미지에 설치되어 있어야 한다. 실행 시
설치 누락 오류가 나오면 이미지에 `ros-jazzy-rmw-zenoh-cpp`를 설치한 뒤
재빌드한다.
