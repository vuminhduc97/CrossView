#pragma once

#include "CrossView.h"

namespace CrossViewer {

    class CrossView::Impl {
    public:
        Impl();
        ~Impl();

        bool init();
        bool createWindow(const wchar_t* title, int width, int height);
        void shutdown();
    };

} // namespace CrossViewer
