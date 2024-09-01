# CrossView
Minimal Cross-Platform Window Manager

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
