project(fract)
cmake_minimum_required(VERSION 3.5)

find_package(PkgConfig)

# pkg_check_modules(GTKMM gtkmm-3.0)

set(EXECUTABLE_OUTPUT_PATH ../bin)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
	../src/main.cpp
	../src/BitMap.cpp
	../src/Mandelbrot.cpp
)

link_directories(
	# ${GTKMM_LIBRARY_DIRS}
)

include_directories(
	../include
	${GTKMM_INCLUDE_DIRS}
)

target_link_libraries(
	${PROJECT_NAME}
	# ${GTKMM_LIBRARIES}
)


