cmake_minimum_required(VERSION 3.16)
project(algorithm_find)

set(CMAKE_CXX_STANDARD 14)

# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS}
        ..
        ../../sort
        )

add_executable(algotithm_find.exe  main.cpp gtest.cpp ../find.cpp)

# 链接测试库GTest 依赖 pthread 库, 所以要链接.
# 特别提示: pthread 库一定要写在 ${GTEST_BOTH_LIBRARIES} 的后面, 否则编译时会报错,
target_link_libraries( algotithm_find.exe
        ${GTEST_BOTH_LIBRARIES}
        pthread )

# 添加到测试
#gtest_discover_tests(test_my_class)
