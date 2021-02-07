# 示例程序 #

`examples/example_uros.c`: 包含了uros ping-pong的实例代码。Client端(BSP)订阅/microROS/ping消息，收到消息后，发送/microROS/pong消息到Agent端(ROS2).

## 准备工作 ##
- 在Ubuntu 20.04 LTS上安装ROS 2 Foxy FitzRoy，参考[链接](https://index.ros.org/doc/ros2/Installation/Foxy/Linux-Install-Debians/)
- 安装完ROS2后，使用如下指令安装Micro-ROS
```
# Source the ROS 2 installation
source /opt/ros/foxy/setup.bash

# Create a workspace and download the micro-ROS tools
mkdir microros_ws
cd microros_ws
git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup

# Update dependencies using rosdep
sudo apt update && rosdep update
rosdep install --from-path src --ignore-src -y

# Install pip
sudo apt-get install python3-pip

# Build micro-ROS tools and source them
colcon build
source install/local_setup.bash
```
- 创建Micro-ROS Agent
```
# Download micro-ROS-Agent packages
ros2 run micro_ros_setup create_agent_ws.sh
# Build step
ros2 run micro_ros_setup build_agent.sh
source install/local_setup.bash
```
- 运行Micro-ROS Agent
   - UDP: `ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888`
   - TCP: `ros2 run micro_ros_agent micro_ros_agent tcp4 --port 8888`
   - Serial: `ros2 run micro_ros_agent micro_ros_agent serial --dev [device]`

## 运行示例 ##

- 配置menuconfig使能Micro-XRCE-DDS-Client软件包并包含示例代码
- pkgs --update获取软件包代码
- 编译运行`bsp/qemu-vexpress-a9`
- 在控制台输入uros_test指令
- 如果成功将创建跟Micro-ROS Agent的连接，并等待/microROS/ping的消息
- 在电脑上打开新的终端，输入如下指令监听/microROS/pong。注意这时还没有消息发过来，因为还未发送ping指令给Client
```
source /opt/ros/foxy/setup.bash
ros2 topic echo /microROS/pong
```
- 打开另外一个新的终端，输入如下指令，发送/microROS/ping消息给Client端
```
source /opt/ros/foxy/setup.bash
# Send a fake ping
ros2 topic pub /microROS/ping std_msgs/msg/Header '{frame_id: "fake_ping"}'
```

## 示例结果 ##

这是示例的结果。
