# Micro-XRCE_DDS-Client

## 1、Introduction

eProsima Micro XRCE-DDS is an open-source wire protocol that implements the OMG DDS for eXtremely Resource Constrained Environment standard (DDS-XRCE). The aim of the DDS-XRCE protocol is to provide access to the DDS Global-Data-Space from resource-constrained devices. This is achieved thanks to a client-server architecture, where low resource devices, called XRCE Clients, are connected to a server, called XRCE Agent, which acts on behalf of its clients in the DDS Global-Data-Space.

This repository is a package for RT-Thread which includes Micro XRCE-DDS Client library and provide the ROS2 topic public/subscribe ability.

### 1.1 Content Architecture

| Name | Description |
| ---- | ---- |
| docs  | Document folder |
| examples | Example folder, which contains micro-ros ping-pong demo |
| inc  | Header folder |
| src  | Source folder |

### 1.2 License

Apache license v2.0

### 1.3 Dependency

- RT-Thread 3.0+

## 2、How to Enable Micro-XRCE_DDS-Client

Enable Micro-XRCE_DDS-Client package in menuconfig at the belowing path:

```
RT-Thread online packages
    tools packages --->
        [*] Micro-XRCE_DDS-Client
```

> To enable examples, add `MICRO_XRCE_DDS_CLIENT_USING_EXAMPLE` in rtconfig.h

## 3、Usage

> 说明：在这里介绍 package 的移植步骤、使用方法、初始化流程、准备工作、API 等等，如果移植或 API 文档内容较多，可以将其独立至 `docs` 目录下。

在打开 hello package 后，当进行 bsp 编译时，它会被加入到 bsp 工程中进行编译。

* [eProsima Document](https://micro-xrce-dds.docs.eprosima.com/en/latest/)
* [Micro-ROS Document](https://micro-ros.github.io/docs/concepts/middleware/Micro_XRCE-DDS/)
* For more documemt, please check `doc` folder.

## 4、Notice

> This package is only tested on ROS2 Fosy, for other ROS distribution is not tested.

## 5、Communication

* Maintainer：Jiachi
