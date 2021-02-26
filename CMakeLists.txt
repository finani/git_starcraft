cmake_minimum_required(VERSION 3.17)
project(cpp_onboarding_run)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_onboarding_run src/main.cpp src/units.cpp include/units/units.h)
