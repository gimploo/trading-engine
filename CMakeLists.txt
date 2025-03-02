cmake_minimum_required(VERSION 3.5)
project(TradingEngine CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_GENERATOR "Ninja")

cmake_minimum_required()


add_executable(TradingEngine src/presentation/main.cpp)
