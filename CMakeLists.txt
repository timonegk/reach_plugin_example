cmake_minimum_required(VERSION 3.7)
project(reach_plugin_example VERSION 1.0 LANGUAGES CXX)

find_package(reach REQUIRED)
find_package(boost_plugin_loader REQUIRED)
find_package(ament_cmake REQUIRED)

add_library(
  ${PROJECT_NAME}_evaluator SHARED
  src/evaluator.cpp
)
target_include_directories(${PROJECT_NAME}_evaluator PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                                  $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME}_evaluator PUBLIC reach::reach)

add_library(${PROJECT_NAME} SHARED src/plugin.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_evaluator)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_evaluator DESTINATION lib)

ament_package()
