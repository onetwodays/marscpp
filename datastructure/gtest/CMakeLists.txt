cmake_minimum_required(VERSION 3.16)
set(appName "datastructure.exe")
project(${appName})

set(CMAKE_CXX_STANDARD 14)

# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS}
        ..
        )





add_executable(${appName} main.cpp
        gtest.cpp
        ../ut_dict.c
        ../ut_list.c
        ../ut_skiplist.c
        ../ut_sds.c
        ../ds_priorityqueue.cpp
        ../cyclequeue.cpp ../cyclequeue.h ../bitmap.cpp ../bitmap.h "../ut_array_stack.h" ../ut_array_stack.c ../ut_dynarray_stack.h ../ut_dynarray_stack.c ../ut_ptr_stack.h ../ut_ptr_stack.c ../ut_bst.h ../ut_bst.c)

# 链接测试库GTest 依赖 pthread 库, 所以要链接.
# 特别提示: pthread 库一定要写在 ${GTEST_BOTH_LIBRARIES} 的后面, 否则编译时会报错,
target_link_libraries( ${appName}
        ${GTEST_BOTH_LIBRARIES}
        pthread )

# 添加到测试
#gtest_discover_tests(test_my_class)
