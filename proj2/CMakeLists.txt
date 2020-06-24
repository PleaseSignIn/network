# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (proj2)

# 指定生成目标
add_executable(TCPClient TCP/myTCPClient.cpp TCP/TCPClientBase.cpp)
add_executable(TCPServer TCP/myTCPServer.cpp TCP/TCPServerBase.cpp)
add_executable(UDPClient UDP/myUDPClient.cpp UDP/UDPClientBase.cpp)
add_executable(UDPServer UDP/myUDPServer.cpp UDP/UDPServerBase.cpp)
add_executable(UDSClient UnixDomain/myUDSClient.cpp UnixDomain/UDSClientBase.cpp)
add_executable(UDSServer UnixDomain/myUDSServer.cpp UnixDomain/UDSServerBase.cpp)
