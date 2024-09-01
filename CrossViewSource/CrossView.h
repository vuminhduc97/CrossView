// CrossView.h
#pragma once

#include <memory>

#ifdef _WIN32
#ifdef CROSSVIEW_EXPORTS
#define CROSSVIEW_API __declspec(dllexport)
#else
#define CROSSVIEW_API __declspec(dllimport)
#endif
#else
#define CROSSVIEW_API
#endif

namespace CrossViewer {

    class CROSSVIEW_API CrossView {
    public:
        CrossView();
        ~CrossView();

        bool init();
        bool createWindow(const wchar_t* title, int width, int height);
        void shutdown();

        static std::unique_ptr<CrossView> createCrossView();

    private:
        class CROSSVIEW_API Impl; // Ensure Impl is also marked for DLL export
        std::unique_ptr<Impl> impl; // Pointer to implementation
    };

} // namespace CrossViewer
