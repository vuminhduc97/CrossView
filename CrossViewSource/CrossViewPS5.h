#pragma once

#include "CrossView.h"

namespace CrossViewer {

    class CrossViewPS5 : public CrossView {
    public:
        CrossViewPS5();
        ~CrossViewPS5() override;

        void createWindow(const wchar_t* title, int width, int height) override;
        void mainLoop() override;
        void shutdown() override;
        void updateViewport(int x, int y, int width, int height) override;
        void setSplitScreen(bool enabled) override;
        void setupVR() override;

    private:
        // PS5-specific data members
    };

} // namespace CrossViewer
