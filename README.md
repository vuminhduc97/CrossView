<img align="left" src="image/1.jpg" width="100px"/>

# CrossView - Minimal Modern Cross-Platform Window Manager

CrossView is a cross-platform library designed for creating and managing windows across multiple platforms. It abstracts platform-specific window management code into a unified interface, allowing you to create and manipulate windows in a platform-agnostic way. 

## Features

- Cross-platform support for Windows, macOS, Linux, Android, iOS, WebAssembly, PS5, Xbox, and a No-op/Console mode.
- Window Creation and Management.
- Platform-specific implementation details hidden behind a common interface.
- Namespace 'CrossViewer' Prevents Global Code Leaks
- C++20 and Factory Pattern Design
- Platform-Specific Factories
- Memory Management and Error Handling
You’re using std::unique_ptr to manage the CrossView object, which is a safe and efficient choice.

- Split-Screen and VR Features
In CrossViewNoop, the setSplitScreen and setupVR methods are stubbed out. Ensure that these features are appropriately implemented in the platform-specific classes where applicable.

- Tested in Windows 10 & 11 With Console headless and WindowsDesktopApplication + headless mode.

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
   git clone https://github.com/Autodidac/CrossView.git
   cd CrossView
```

### Generate build files using CMake:
Run cmake to generate the build files, then compile:

### Build the project:
Basic Build:
```sh
Copy code
mkdir build
cd build
cmake ..
cmake --build .
```
Enable Headless Mode:

To build with headless mode enabled, pass the option when running cmake:
```sh
Copy code
cmake .. -DENABLE_HEADLESS=ON
cmake --build .
```
Run:

After building, you can run the generated executable. If you built with headless mode, the console window will be allocated as needed.


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

