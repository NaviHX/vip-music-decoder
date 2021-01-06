cmake_minimum_required(VERSION 2.9)
project(vip-music-decoder)

aux_source_directory(./src SRC)
add_executable(qmcdump ${SRC})

set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -O2")
add_definitions("-Wall -g")
