#include "CrossViewWin32.h"
#include <iostream>
#include <string>

namespace CrossViewer {

    CrossViewWin32::CrossViewWin32()
        : hwnd(nullptr), hInstance(GetModuleHandle(nullptr)), splitScreenEnabled(false) {
    }

    CrossViewWin32::~CrossViewWin32() {
        shutdown();
    }

    void CrossViewWin32::createWindow(const wchar_t* title, int width, int height) {
        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = hInstance;
        wc.lpszClassName = L"CrossViewClass";

        if (!RegisterClass(&wc)) {
            throw std::runtime_error("Failed to register window class with error: " + std::to_string(GetLastError()));
        }

        hwnd = CreateWindowEx(
            0,
            L"CrossViewClass",
            title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, width, height,
            nullptr,
            nullptr,
            hInstance,
            this // Pass this pointer to the window
        );

        if (!hwnd) {
            throw std::runtime_error("Failed to create window with error: " + std::to_string(GetLastError()));
        }

        ShowWindow(hwnd, SW_SHOW);
        UpdateWindow(hwnd);
    }

    void CrossViewWin32::mainLoop() {
        MSG msg;
        while (GetMessage(&msg, nullptr, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void CrossViewWin32::shutdown() {
        if (hwnd) {
            DestroyWindow(hwnd);
            hwnd = nullptr;
        }
    }

    void CrossViewWin32::updateViewport(int x, int y, int width, int height) {
        std::cout << "Updating Windows viewport to x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << std::endl;
        // Implement viewport update logic here
    }

    void CrossViewWin32::setSplitScreen(bool enabled) {
        splitScreenEnabled = enabled;
        // Implement split-screen logic here
    }

    void CrossViewWin32::setupVR() {
        // Implement VR setup logic here
    }

    LRESULT CALLBACK CrossViewWin32::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        CrossViewWin32* window = nullptr;

        if (uMsg == WM_NCCREATE) {
            CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
            window = reinterpret_cast<CrossViewWin32*>(pCreate->lpCreateParams);
            SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
        }
        else {
            window = reinterpret_cast<CrossViewWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        }

        if (window) {
            switch (uMsg) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
                // Handle other messages here
            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
            }
        }

        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

} // namespace CrossViewer
