cmake_minimum_required(VERSION 3.15)
project(SpaceInvaders LANGUAGES CXX) # specify using cpp for cmake

set(CMAKE_CXX_STANDARD 17) # enables cpp 17 features

add_definitions(-D_CRT_SECURE_NO_WARNINGS) # diables unsafe functions for simplicity

add_executable(
SpaceInvaders main.cpp 
"Player.cpp" 
"Bullet.cpp"
) # add files to compile


if(WIN32)
	target_link_libraries(SpaceInvaders PRIVATE User32)
endif() # windows api function for console manipulation requires this library






