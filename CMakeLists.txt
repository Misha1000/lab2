message(STATUS "in ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt")
cmake_minimum_required(VERSION 3.10)

project(Lab2)

set(CMAKE_CXX_STANDARD 17)
message("set CMAKE_CXX_STANDARD to ${CMAKE_CXX_STANDARD}")

set(TARGET_NAME "lab2")
message("set TARGET_NAME to ${TARGET_NAME}")

set(FILESYSTEM_LINKER_FLAGS "-lstdc++fs")

file(GLOB SRC_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(${TARGET_NAME} ${SRC_FILES})

target_link_libraries(${TARGET_NAME} ${FILESYSTEM_LINKER_FLAGS})

target_include_directories(${TARGET_NAME}
	PUBLIC
		${PROJECT_SOURCE_DIR}/inc
)
