# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.12.0)

if(CMAKE_BUILD_RPATH)
    message("CMAKE_BUILD_RPATH: ${CMAKE_BUILD_RPATH}")
endif()

# 项目信息
project (perform_c++)
set (PERFORM_C++_VERSION 1)
set (PERFORM_C++_VERSION 0)
set (PERFORM_C++_VERSION 0)

# 设置编译选项
if (CMAKE_BUILD_RPATH AND (CMAKE_BUILD_TYPE MATCHES GTEST))
    #set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage") 
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11 -g -fprofile-arcs -ftest-coverage") 
endif()

# 目录下的所有源文件
aux_source_directory(stl PERFORM_C++_SRC_FILES)
aux_source_directory(gtest PERFORM_C++_TEST_FILES)

# 头文件目录
include_directories(${PROJECT_SOURCE_DIR}/stl)

# 库文件目录
include_directories(${CMAKE_BUILD_RPATH}/include)
link_directories(${CMAKE_BUILD_RPATH}/lib)

if (CMAKE_BUILD_TYPE MATCHES GTEST)
    #添加编译选项
    add_executable(perform_c++ ${PERFORM_C++_SRC_FILES} 
                    ${PERFORM_C++_TEST_FILES})
    target_link_libraries(perform_c++ PRIVATE gtest)
    target_link_libraries(perform_c++ PRIVATE gcov)
endif()
