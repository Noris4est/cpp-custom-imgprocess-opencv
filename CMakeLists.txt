cmake_minimum_required(VERSION 3.5)

project(custom_imgprocess_opencv VERSION 1.0.0 DESCRIPTION "library for using in your application custom image process funcions based on opencv")

file(GLOB SOURCES 
    src/*.cpp
    tools/*.cpp)
file(GLOB HEADERS 
    include/*.hpp
    tools/*.hpp)

set(LIBNAME custom_cv_imgprocess)

set(OpenCV_DIR /home/vitaly/opencv/install_4_5_2_contrib)
find_package(OpenCV REQUIRED PATHS ${OpenCV_DIR} NO_DEFAULT_PATH)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/tools
	${OpenCV_INCLUDE_DIRS}) #только для быстрого доступа к include'ам

add_library(${LIBNAME} SHARED ${SOURCES} ${HEADERS}) # ${HEADERS} не обязательно, тк нужно только для отладки

target_link_libraries(${LIBNAME} ${OpenCV_LIBS})


#demo

add_executable(
    demo1 
    demo/demo1.cpp)
target_link_libraries(demo1 ${LIBNAME})
