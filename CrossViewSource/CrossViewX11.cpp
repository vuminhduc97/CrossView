// Start of file: CrossViewX11.cpp
#include "CrossViewX11.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

namespace CrossViewer {

    CrossViewX11::CrossViewX11() : display(XOpenDisplay(nullptr)), window(0), splitScreenEnabled(false) {
        if (!display) {
            throw std::runtime_error("Failed to open X display");
        }
    }

    CrossViewX11::~CrossViewX11() {
        if (display) {
            if (window) {
                XDestroyWindow(display, window);
            }
            XCloseDisplay(display);
        }
    }

    void CrossViewX11::createWindow(const wchar_t* title, int width, int height) {
        if (display) {
            window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, width, height, 1, BlackPixel(display, 0), WhitePixel(display, 0));
            XStoreName(display, window, reinterpret_cast<const char*>(title));
            XSelectInput(display, window, ExposureMask | KeyPressMask);
            XMapWindow(display, window);
        }
        else {
            std::cerr << "Display is not initialized" << std::endl;
        }
    }

    void CrossViewX11::mainLoop() {
        XEvent event;
        while (true) {
            XNextEvent(display, &event);
            if (event.type == ClientMessage) {
                break;
            }
        }
    }

    void CrossViewX11::shutdown() {
        if (display && window) {
            XDestroyWindow(display, window);
        }
    }

    void CrossViewX11::updateViewport(int x, int y, int width, int height) {
        // Note: X11 does not have a direct viewport concept. This is a placeholder.
        std::cout << "Updating X11 viewport with x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << std::endl;
    }

    void CrossViewX11::setSplitScreen(bool enabled) {
        splitScreenEnabled = enabled;
        std::cout << "X11 setSplitScreen called with enabled: " << (enabled ? "true" : "false") << std::endl;
    }

    void CrossViewX11::setupVR() {
        std::cout << "X11 setupVR called." << std::endl;
    }

} // namespace CrossViewer
