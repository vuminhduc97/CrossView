# CrossView
Minimal Cross-Platform Window Manager

CrossView is a cross-platform library designed for creating and managing windows across multiple platforms. It abstracts platform-specific window management code into a unified interface, allowing you to create and manipulate windows in a platform-agnostic way. 

## Features

- Cross-platform support for Windows, macOS, Linux, Android, iOS, WebAssembly, PS5, Xbox, and a noop mode.
- Window creation and management.
- Platform-specific implementation details hidden behind a common interface.

## Supported Platforms

- **Windows** (Win32)
- **macOS** (Cocoa)
- **Linux** (XCB or XLib)
- **Android**
- **iOS** (UIKit)
- **WebAssembly** (Emscripten)
- **PlayStation 5** (PS5)
- **Xbox**
- **No-op** (Headless mode)

## Installation

### Prerequisites

- C++20 or later
- CMake 3.10 or later

### Building

1. Clone the repository:
```sh
   git clone https://github.com/yourusername/CrossView.git
   cd CrossView
```




### Create a build directory:
```sh

mkdir build
cd build

```
### Generate build files using CMake:
```sh

cmake ..

```
### Build the project:
```sh

cmake --build .

```


### Usage
##### Example
```cpp
#include "CrossView.h"

int main() {
    auto crossView = CrossViewer::CrossView::createCrossView();
    if (crossView->init()) {
        crossView->createWindow(L"Example Window", 800, 600);
        // Main loop or additional logic here
        crossView->shutdown();
    }
    return 0;
}
```
### API Reference

```cpp
CrossViewer::CrossView
static std::unique_ptr<CrossView> createCrossView()
bool init()
bool createWindow(const wchar_t* title, int width, int height)
void shutdown()

```


### Platform-specific Implementations
The platform-specific implementation files are organized into separate source files. Each implementation file contains the initialization, window creation, and shutdown code for a specific platform.

-Windows:   CrossViewWin32.cpp and CrossViewWin32.h

-macOS:   CrossViewMac.cpp and CrossViewMac.h

-Linux:   CrossViewLinux.cpp and CrossViewLinux.h

-Android:   CrossViewAndroid.cpp and CrossViewAndroid.h

-iOS:   CrossViewIOS.cpp and CrossViewIOS.h

-WebAssembly:   CrossViewWebAssembly.cpp and CrossViewWebAssembly.h

-PlayStation 5:   CrossViewPS5.cpp and CrossViewPS5.h

-Xbox:   CrossViewXbox.cpp and CrossViewXbox.h

-No-op mode:   CrossViewNoop.cpp and CrossViewNoop.h

### License
This project is licensed under the MIT License. See the LICENSE file for details.

### Contributing
Contributions are welcome! Please see the CONTRIBUTING.md file for guidelines.


#MORE Details!

### 1. Factory Class Design
CrossViewFactory Class: The create() function is defined as a private member in the CrossViewFactory class. It seems this function is intended to be overridden by derived classes, such as platform-specific factories. However, you don't need the private create() function in CrossViewFactory. The factory method should be pure virtual and defined in derived classes.
### 2. Platform-Specific Factories
Ensure each platform-specific factory class, such as CrossViewWin32Factory, CrossViewMacFactory, etc., inherits from CrossViewFactory and implements the create() method correctly.
### 3. Namespace and Include Guards
The code effectively uses namespaces, which is good for preventing name clashes. Ensure that all header files have #pragma once at the top to prevent multiple inclusions.
### 4. Memory Management and Error Handling
You’re using std::unique_ptr to manage the CrossView object, which is a safe and efficient choice. However, it might be a good idea to include more detailed error handling and logging, especially when dealing with platform-specific implementations that may fail.
### 5. Split-Screen and VR Features
In CrossViewNoop, the setSplitScreen and setupVR methods are stubbed out. Ensure that these features are appropriately implemented in the platform-specific classes where applicable.
### 6. Cross-Platform Compatibility
The platform-specific code snippets look good. Ensure that all the necessary platform-specific libraries and frameworks are correctly linked during the build process for each platform.
