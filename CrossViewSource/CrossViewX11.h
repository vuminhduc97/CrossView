// Start of file: CrossViewX11.h
#pragma once

#include "CrossView.h"
#include <X11/Xlib.h>

namespace CrossViewer {

    class CrossViewX11 : public CrossView {
    public:
        CrossViewX11();
        ~CrossViewX11() override;

        void createWindow(const wchar_t* title, int width, int height) override;
        void mainLoop() override;
        void shutdown() override;
        void updateViewport(int x, int y, int width, int height) override;
        void setSplitScreen(bool enabled) override;
        void setupVR() override;

    private:
        Display* display;
        Window window;
        bool splitScreenEnabled;
    };

} // namespace CrossViewer
