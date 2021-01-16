cmake_minimum_required(VERSION 2.9)
project(vip-music-decoder)

set(INC_DIR /usr/local/include)  
set(LINK_DIR /usr/local/lib)
include_directories(${INC_DIR})
link_directories(${LINK_DIR})

aux_source_directory(./src-qmc SRCQMC)
add_executable(qmcdump ${SRCQMC})

aux_source_directory(./src-ncm SRCNCM)
add_executable(ncmdump ${SRCNCM})

set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -O2")
target_link_libraries(ncmdump tag)
add_definitions("-Wall -g")
