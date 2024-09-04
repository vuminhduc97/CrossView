#pragma once

#include "CrossView.h"
#include <windows.h>
#include <stdexcept>

namespace CrossViewer {

    class CrossViewWin32 : public CrossView {
    public:
        CrossViewWin32();
        ~CrossViewWin32() override;

        void createWindow(const wchar_t* title, int width, int height) override;
        void mainLoop() override;
        void shutdown() override;
        void updateViewport(int x, int y, int width, int height) override;
        void setSplitScreen(bool enabled) override;
        void setupVR() override;

    private:
        HWND hwnd;
        HINSTANCE hInstance;
        bool splitScreenEnabled;

        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    };

} // namespace CrossViewer
