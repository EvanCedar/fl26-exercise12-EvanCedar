cmake_minimum_required(VERSION 3.6)
project(ToggleTestExample CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Test REQUIRED)

add_executable(toggleapp main.cpp toggle_widget.h toggle_widget.cpp)
target_link_libraries(toggleapp Qt6::Widgets)

add_executable(toggletest test_toggle_widget.cpp toggle_widget.h toggle_widget.cpp)
target_link_libraries(toggletest Qt6::Widgets Qt6::Test)

enable_testing()
add_test(toggletest toggletest)
