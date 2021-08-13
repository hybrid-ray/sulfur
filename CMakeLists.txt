cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -O3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(VERSION_APPEND "alpha")
project(sulfur VERSION 0.0)
configure_file(./build/cfgs.hpp.in ../src/cfgs.hpp)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/libs/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/libs/libs")

add_executable(sulfur ./src/main.cpp ./src/cfgloader.cpp)
target_link_libraries(sulfur PUBLIC boost_iostreams z)
add_custom_command(TARGET sulfur POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_SOURCE_DIR}/build/sulfur ${CMAKE_CURRENT_SOURCE_DIR}/out/)
