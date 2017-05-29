# This is a folder for your own small program test before patching it into the main project

# Use this CMakeLists to build project on this folder

cmake_minimum_required(VERSION 3.8.1)

#for user using MINGW
#run using command

# cmake -G "MinGW Makefiles"
# make must not be in path if you use MingGW
# instead, use MinGW make

# if you like, you can use clang?????
# i don't know about this

## MinGW support make, other than MSYS

# set your gcc and g++ compiler here
# space is "\ "  give a space
# "(" and ")" are "\(" and "\)"
SET(CMAKE_C_COMPILER C:/Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev2/mingw32/bin/gcc.exe)
SET(CMAKE_CXX_COMPILER C:/Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev2/mingw32/bin/g++.exe)


# output file exe location
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# the project name
project (spike)

# configure src
# more general
	file(GLOB SOURCES "src/*.cpp")


# the included folder for <>
include_directories(include)

# compile with release for other computers
# -static -static-libgcc -static-libstdc++ -fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8 -std=c++11

# compile with debug only you
# -g -fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8 -std=c++11

set(WARNING "-Wall")
set(PUBLIC "-static -static-libgcc -static-libstdc++")
set(IDENTIFIER "-fextended-identifiers --input-charset=utf-8 -finput-charset=utf-8 --exec-charset=utf-8")
set(CPPVERSION "-std=c++11")

# this is for public build, orther machine can run
#set(CMAKE_CXX_FLAGS ${WARNING}\ ${PUBLIC}\ ${IDENTIFIER}\ ${CPPVERSION})

# for personal build
set(CMAKE_CXX_FLAGS ${WARNING}\ ${IDENTIFIER}\ ${CPPVERSION})
message(${CMAKE_CXX_FLAGS})

# the project executable with src
add_executable(spike ${SOURCES})