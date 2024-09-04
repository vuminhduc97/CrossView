cmake_minimum_required(VERSION 3.15)
project(CrossView)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Source files
set(SOURCES
    CrossView.cpp
    CrossViewWin32.cpp
    CrossViewNoop.cpp
)

# Add library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Set compile options
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /EHsc /D_CRT_SECURE_NO_WARNINGS)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()

# Set include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

# Optionally, you can configure the library to be built as shared by setting this option:
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
# if (BUILD_SHARED_LIBS)
#     add_library(${PROJECT_NAME} SHARED ${SOURCES})
# else ()
#     add_library(${PROJECT_NAME} STATIC ${SOURCES})
# endif ()
