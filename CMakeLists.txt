cmake_minimum_required(VERSION 3.23)
project(LinkSystem)

set(CMAKE_CXX_STANDARD 11)

# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(LinkSystem main.cpp Utils/CrcUtil.cpp Utils/CrcUtil.h System/Link22.cpp System/Link22.h System/ConstructCenter.cpp System/ConstructCenter.h Utils/MsgUtil.cpp Utils/MsgUtil.h Utils/AES.cpp Utils/AES.h System/F0nMessage.cpp System/F0nMessage.h System/FnpMessage.cpp System/FnpMessage.h System/FnMessage.cpp System/FnMessage.h)
