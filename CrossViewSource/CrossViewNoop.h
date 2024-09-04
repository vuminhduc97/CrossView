#pragma once

#include "CrossView.h"

namespace CrossViewer {

    class CrossViewNoop : public CrossView {
    public:
        CrossViewNoop();
        ~CrossViewNoop() override;

        void createWindow(const wchar_t* title, int width, int height) override;
        void mainLoop() override;
        void shutdown() override;
        void updateViewport(int x, int y, int width, int height) override;
        void setSplitScreen(bool enabled) override;
        void setupVR() override;
    };

} // namespace CrossViewer