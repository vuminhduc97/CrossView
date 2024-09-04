cmake_minimum_required(VERSION 3.15)
project(CrossViewExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Source files
set(SOURCES
    CrossViewExample.cpp
    CrossView.cpp
    CrossViewWin32.cpp
    CrossViewNoop.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries (if any)
# target_link_libraries(${PROJECT_NAME} ...)

# Set compile options
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive- /EHsc /D_CRT_SECURE_NO_WARNINGS)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()

# Set subsystem depending on build mode
if (MSVC)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    else ()
        set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
    endif ()
endif ()

# Add options to enable headless mode or console mode
option(ENABLE_HEADLESS "Enable headless mode" OFF)

if (ENABLE_HEADLESS)
    target_compile_definitions(${PROJECT_NAME} PRIVATE _CONSOLE)
endif ()
