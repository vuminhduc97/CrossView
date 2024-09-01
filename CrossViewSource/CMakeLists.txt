
### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)
project(CrossView VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the CrossView library
add_library(CrossView STATIC
    CrossView.cpp
    CrossViewWin32.cpp
    CrossViewMac.cpp
    CrossViewLinux.cpp
    CrossViewAndroid.cpp
    CrossViewWebAssembly.cpp
    CrossViewPS5.cpp
    CrossViewXbox.cpp
    CrossViewNoop.cpp
)

# Include directories for the library
target_include_directories(CrossView PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Define the platform-specific source files
target_sources(CrossView PRIVATE
    CrossViewWin32.cpp
    CrossViewMac.cpp
    CrossViewLinux.cpp
    CrossViewAndroid.cpp
    CrossViewWebAssembly.cpp
    CrossViewPS5.cpp
    CrossViewXbox.cpp
    CrossViewNoop.cpp
)

# Define the platform-specific headers
target_sources(CrossView PRIVATE
    CrossViewWin32.h
    CrossViewMac.h
    CrossViewLinux.h
    CrossViewAndroid.h
    CrossViewWebAssembly.h
    CrossViewPS5.h
    CrossViewXbox.h
    CrossViewNoop.h
)

# Link dependencies
# Add any dependencies you might need here

# Installation rules (optional)
install(TARGETS CrossView DESTINATION lib)
install(FILES CrossView.h DESTINATION include)

