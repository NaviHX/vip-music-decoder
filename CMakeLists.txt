cmake_minimum_required(VERSION 2.9)
project(vip-music-decoder)

aux_source_directory(./src-qmc SRCQMC)
add_executable(qmcdump ${SRCQMC})

aux_source_directory(./src-ncm SRCNCM)
add_executable(ncmdump ${SRCNCM})

set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -O2")
add_definitions("-Wall -g")
