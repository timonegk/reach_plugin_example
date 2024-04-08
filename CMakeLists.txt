cmake_minimum_required(VERSION 3.7)
project(reach_plugin_example VERSION 1.0 LANGUAGES CXX)

find_package(reach REQUIRED)
find_package(boost_plugin_loader REQUIRED)
find_package(ament_cmake REQUIRED)

add_library(
  ${PROJECT_NAME} SHARED
  src/evaluator.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                                  $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} PUBLIC reach::reach)

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

ament_package()
