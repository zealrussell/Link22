cmake_minimum_required(VERSION 3.23)
project(LinkSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkSystem main.cpp Utils/CrcUtil.cpp Utils/CrcUtil.h System/Link22.cpp System/Link22.h System/ConstructCenter.cpp System/ConstructCenter.h Utils/MsgUtil.cpp Utils/MsgUtil.h Utils/AES.cpp Utils/AES.h)
