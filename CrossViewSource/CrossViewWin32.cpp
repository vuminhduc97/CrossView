#define CROSSVIEW_EXPORTS
#include "CrossViewWin32.h"

namespace CrossViewer {

    CrossView::Impl::Impl() {
        // Win32-specific initialization code
    }

    CrossView::Impl::~Impl() {
        // Win32-specific cleanup code
    }

    bool CrossView::Impl::init() {
        // Win32-specific initialization code
        return true;
    }

    bool CrossView::Impl::createWindow(const wchar_t* title, int width, int height) {
        // Win32-specific window creation code
        return true;
    }

    void CrossView::Impl::shutdown() {
        // Win32-specific shutdown code
    }

} // namespace CrossViewer
