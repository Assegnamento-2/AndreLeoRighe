cmake_minimum_required(VERSION 3.0.0)
project(Rail VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Rail main.cpp)

set(CPACK_PROJECT_NAME Rail)
set(CPACK_PROJECT_VERSION 0.1.0)
include(CPack)
