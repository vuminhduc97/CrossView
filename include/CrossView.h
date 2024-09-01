#pragma once

#include <memory>
#include <vector>
#include <string>
#include <tuple>
#include <stdexcept>
#include <type_traits>

// Abstract base class for window management
class CrossView {
public:
    virtual ~CrossView() = default;
    virtual bool init() = 0;
    virtual bool createWindow(const std::wstring& title, int width, int height) = 0;
    virtual void shutdown() = 0;
    virtual void run() = 0;

    virtual void addViewport(int x, int y, int width, int height) {
        viewports.emplace_back(x, y, width, height);
    }

    const std::vector<std::tuple<int, int, int, int>>& getViewports() const {
        return viewports;
    }

protected:
    std::vector<std::tuple<int, int, int, int>> viewports;
};

// Platform-specific CrossView implementations

#if defined(_WIN32)
#include <windows.h>

class WindowsCrossView : public CrossView {
public:
    bool init() override {
        // Initialize Windows-specific resources
        return true;
    }

    bool createWindow(const std::wstring& title, int width, int height) override {
        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = L"SampleWindowClass";

        RegisterClass(&wc);

        hwnd = CreateWindowEx(
            0, L"SampleWindowClass", title.c_str(),
            WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height,
            nullptr, nullptr, GetModuleHandle(nullptr), this
        );

        if (!hwnd) return false;

        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
        return true;
    }

    void shutdown() override {
        if (hwnd) {
            DestroyWindow(hwnd);
        }
    }

    void run() override {
        MSG msg;
        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

private:
    HWND hwnd = nullptr;

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        if (uMsg == WM_DESTROY) {
            PostQuitMessage(0);
            return 0;
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
};
#elif defined(__linux__)
#include <X11/Xlib.h>

class LinuxCrossView : public CrossView {
public:
    bool init() override {
        display = XOpenDisplay(nullptr);
        if (!display) return false;
        return true;
    }

    bool createWindow(const std::string& title, int width, int height) override {
        int screen = DefaultScreen(display);
        Window root = RootWindow(display, screen);

        window = XCreateSimpleWindow(display, root, 0, 0, width, height, 1,
            BlackPixel(display, screen), WhitePixel(display, screen));
        XSetStandardProperties(display, window, title.c_str(), title.c_str(), None, nullptr, 0, nullptr);
        XSelectInput(display, window, ExposureMask | KeyPressMask);
        XMapWindow(display, window);
        return true;
    }

    void shutdown() override {
        if (display) {
            XDestroyWindow(display, window);
            XCloseDisplay(display);
        }
    }

    void run() override {
        XEvent event;
        while (true) {
            XNextEvent(display, &event);
            if (event.type == KeyPress) break; // Simple exit on key press
        }
    }

private:
    Display* display = nullptr;
    Window window;
};
#elif defined(__APPLE__)
#include <Cocoa/Cocoa.h>

class MacOSCrossView : public CrossView {
public:
    bool init() override {
        // Initialize macOS-specific resources
        return true;
    }

    bool createWindow(const std::string& title, int width, int height) override {
        NSApplication* app = [NSApplication sharedApplication];
        NSWindow* window = [[NSWindow alloc]initWithContentRect:NSMakeRect(0, 0, width, height)
            styleMask : (NSWindowStyleMaskTitled |
                NSWindowStyleMaskClosable |
                NSWindowStyleMaskResizable)
            backing : NSBackingStoreBuffered
            defer : NO];
        [window setTitle : [NSString stringWithUTF8String : title.c_str()] ] ;
        [window makeKeyAndOrderFront : nil] ;
        return true;
    }

    void shutdown() override {
        // Clean up macOS-specific resources
    }

    void run() override {
        [[NSApplication sharedApplication]run];
    }
};
#elif defined(XBOX)
#include <XboxSpecificSDK.h>

class XboxCrossView : public CrossView {
public:
    bool init() override {
        // Initialize Xbox SDK
        return true;
    }

    bool createWindow(const std::string& title, int width, int height) override {
        // Create an Xbox window
        return true;
    }

    void shutdown() override {
        // Clean up Xbox SDK resources
    }

    void run() override {
        // Run the Xbox main loop
    }
};
#elif defined(PS5)
#include <PS5SpecificSDK.h>

class PS5CrossView : public CrossView {
public:
    bool init() override {
        // Initialize PS5 SDK
        return true;
    }

    bool createWindow(const std::string& title, int width, int height) override {
        // Create a PS5 window
        return true;
    }

    void shutdown() override {
        // Clean up PS5 SDK resources
    }

    void run() override {
        // Run the PS5 main loop
    }
};
#endif

// Factory function to create the appropriate CrossView implementation
inline std::unique_ptr<CrossView> createCrossView() {
#if defined(_WIN32)
    return std::make_unique<WindowsCrossView>();
#elif defined(__linux__)
    return std::make_unique<LinuxCrossView>();
#elif defined(__APPLE__)
    return std::make_unique<MacOSCrossView>();
#elif defined(XBOX)
    return std::make_unique<XboxCrossView>();
#elif defined(PS5)
    return std::make_unique<PS5CrossView>();
#else
    static_assert(false, "Unsupported platform");
    return nullptr;
#endif
}
