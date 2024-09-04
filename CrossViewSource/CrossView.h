#pragma once

#include <memory>

namespace CrossViewer {

    class CrossView {
    public:
        virtual ~CrossView() = default;

        static std::unique_ptr<CrossView> createCrossView();

        virtual void createWindow(const wchar_t* title, int width, int height) = 0;
        virtual void mainLoop() = 0;
        virtual void shutdown() = 0;
        virtual void updateViewport(int x, int y, int width, int height) = 0;
        virtual void setSplitScreen(bool enabled) = 0;
        virtual void setupVR() = 0;

    protected:
        CrossView() = default;
    };

} // namespace CrossViewer
