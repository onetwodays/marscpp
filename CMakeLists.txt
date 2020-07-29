cmake_minimum_required(VERSION 3.16)
project(marsc__)

set(CMAKE_CXX_STANDARD 14)
#开启测试
enable_testing()

find_library(SSL_LIB NAMES ssl)
if (NOT SSL_LIB)
    message(FATAL_ERROR "Fail to find ssl")
endif()

find_library(CRYPTO_LIB NAMES crypto)
if (NOT CRYPTO_LIB)
    message(FATAL_ERROR "Fail to find crypto")
endif()

find_path(GFLAGS_INCLUDE_PATH gflags/gflags.h)
find_library(GFLAGS_LIBRARY NAMES gflags libgflags)
if((NOT GFLAGS_INCLUDE_PATH) OR (NOT GFLAGS_LIBRARY))
    message(FATAL_ERROR "Fail to find gflags")
endif()

include(FindThreads)
include(FindProtobuf)

include_directories(${GFLAGS_INCLUDE_PATH})

include_directories(./thirdparty/brpc/include)
link_directories(./thirdparty/brpc/lib)

set(DYNAMIC_LIB
        ${CMAKE_THREAD_LIBS_INIT}
        ${GFLAGS_LIBRARY}
        ${PROTOBUF_LIBRARIES}
        #${LEVELDB_LIB}
        ${SSL_LIB}
        ${CRYPTO_LIB}
        dl
        )
add_executable(marsc++.exe main.cpp )
target_link_libraries(marsc++.exe libbrpc.a  ${DYNAMIC_LIB} )
#添加测试目录
add_subdirectory(algorithm/sort/gtest)
add_subdirectory(algorithm/find/gtest)
add_subdirectory(datastructure/gtest)
add_subdirectory(letcode/gtest)
