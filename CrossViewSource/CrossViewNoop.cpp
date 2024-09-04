#include "CrossViewNoop.h"
#include <iostream>

namespace CrossViewer {

    CrossViewNoop::CrossViewNoop() {
        // Initialize headless-specific resources
    }

    CrossViewNoop::~CrossViewNoop() {
        // Cleanup headless-specific resources
    }

    void CrossViewNoop::createWindow(const wchar_t* title, int width, int height) {
        std::wcout << L"Creating headless window with title: " << title << L", width: " << width << L", height: " << height << std::endl;
        // Implement headless window creation logic
    }

    void CrossViewNoop::mainLoop() {
        std::cout << "Headless main loop started." << std::endl;
        // Implement headless main loop logic
    }

    void CrossViewNoop::shutdown() {
        std::cout << "Shutting down headless window." << std::endl;
        // Implement headless shutdown logic
    }

    void CrossViewNoop::updateViewport(int x, int y, int width, int height) {
        std::cout << "Updating headless viewport with x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << std::endl;
        // Implement viewport update logic
    }

    void CrossViewNoop::setSplitScreen(bool enabled) {
        std::cout << "Headless setSplitScreen called with enabled: " << (enabled ? "true" : "false") << std::endl;
    }

    void CrossViewNoop::setupVR() {
        std::cout << "Headless setupVR called." << std::endl;
    }

} // namespace CrossViewer