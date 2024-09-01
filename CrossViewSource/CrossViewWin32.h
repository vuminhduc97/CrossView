#pragma once

#include "CrossView.h"
#include <Windows.h>

// namespace CrossViewer
namespace CrossViewer {

    class CrossView::Impl {
    public:
        Impl();
        ~Impl();

        bool init();
        bool createWindow(const wchar_t* title, int width, int height);
        void shutdown();
    private:
        HWND hwnd; // Handle to the window
    };

} // namespace CrossViewer
