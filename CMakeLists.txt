cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0012 NEW)
project(c02)
set(CMAKE_CXX_STANDARD 11)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
endif()

find_package(OpenCV 4.0.0 REQUIRED)
message("OpenCV version: ${OPENCV_VERSION}")

# include_directories(${OpenCV_INCLUDE_DIRS})
# link_directories(${OpenCV_LIB_DIR})

add_executable(sample1 sample1.cpp)
target_link_libraries(sample1 ${OpenCV_LIBS} ${CONAN_LIBS} -lprotobuf)

add_executable(sample2 sample2.cpp)
target_link_libraries(sample2 ${OpenCV_LIBS} ${CONAN_LIBS} -lprotobuf)

add_executable(sample3 sample3.cpp)
target_link_libraries(sample3 ${OpenCV_LIBS} ${CONAN_LIBS} -lprotobuf)

