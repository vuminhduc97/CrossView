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




Create a build directory:
```sh

mkdir build
cd build

```
Generate build files using CMake:
```sh

cmake ..

```
Build the project:
```sh

cmake --build .

```


Usage
Example


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
API Reference
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
