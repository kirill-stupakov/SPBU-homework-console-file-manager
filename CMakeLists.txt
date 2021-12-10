cmake_minimum_required(VERSION 3.20)
project(ConsoleFileManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(untitled main.cpp FileManagerCore.cpp FileManagerCore.h ConsoleFileManager.cpp ConsoleFileManager.h FileManagerOption.cpp FileManagerOption.h)
target_link_libraries(untitled stdc++fs)