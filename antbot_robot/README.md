# Antbot

Antbot의 정적인 로봇 정의 패키지다. 실행 코드와 ROS 2 코드는 포함하지 않는다.

~~~text
antbot_robot/
├── __init__.py
├── asset.py                  USD 경로, articulation, actuator, joint 정의
├── sensors.py                카메라 5개와 LiDAR 3개의 Isaac Lab 설정
└── robot_usd/                로봇 USD와 configuration layer
~~~

asset.py는 로봇을 spawn하는 ANTBOT_CFG와 제어 대상 joint 이름을 제공한다.
sensors.py는 로봇 USD의 센서 frame 아래에 생성할 카메라와 RayCaster 설정을
제공한다. front RGB 카메라와 front depth 카메라는 별도 CameraCfg이며,
depth 카메라는 distance_to_image_plane 데이터만 렌더링한다.

시뮬레이션 생성, ROS 2 통신, WebRTC, Action Graph는 antbot_runner가 담당한다.
