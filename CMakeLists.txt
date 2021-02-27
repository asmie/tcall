# CMakeLists file written by Piotr "asmie" Olszewski
# Project: tcall

cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(tcall)

# Versioning
set (TCALL_VERSION_MAJOR 0)
set (TCALL_VERSION_MINOR 0)
set (TCALL_VERSION_REV 1)
set (TCALL_VERSION ${TCALL_VERSION_MAJOR}.${TCALL_VERSION_MINOR}.${TCALL_VERSION_REV} )

# Configuration
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Compilation options
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -pipe)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g3 -ggdb")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -0s")
	
	set(CMAKE_EXE_LINKER_FLAGS "-z now -s")
endif()

# Checking time
include (CheckIncludeFileCXX)
include (CheckCXXSymbolExists)

check_include_file_cxx (cstdlib TCALL_SYSTEM_HAVE_CSTDLIB)

check_cxx_symbol_exists (EXIT_SUCCESS cstdlib TCALL_SYSTEM_HAVE_EXIT_SUCCESS)

# Configuration file
configure_file (
  "${PROJECT_SOURCE_DIR}/src/tcall_config.h.in"
  "generated/tcall_config.h"
  )

# Find source files
file(GLOB SOURCES src/*.cpp)

# Include header files
include_directories(src ${CMAKE_CURRENT_BINARY_DIR}/generated)

# Find packages
# # Threads
find_package(Threads REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Threads::Threads)

# Install executable
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})


# Testing time
enable_testing()

# Try to find GTest
find_package(GTest)

if(GTEST_FOUND)
	include_directories(src ${CMAKE_CURRENT_BINARY_DIR}/generated ${GTEST_INCLUDE_DIR})
	file(GLOB TEST_SOURCES tests/unit/*.cpp ${SOURCES})
	add_executable(${PROJECT_NAME}_unit ${TEST_SOURCES})
	target_link_libraries(${PROJECT_NAME}_unit PUBLIC ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} )
	add_test(${PROJECT_NAME}_unit_test ${PROJECT_NAME}_unit)
endif(GTEST_FOUND)

