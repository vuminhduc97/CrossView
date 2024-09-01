#define CROSSVIEW_EXPORTS
#include "CrossViewNoop.h"

namespace CrossViewer {

    CrossView::Impl::Impl() {
        // No-op initialization code
    }

    CrossView::Impl::~Impl() {
        // No-op cleanup code
    }

    bool CrossView::Impl::init() {
        // No-op initialization code
        return true;
    }

    bool CrossView::Impl::createWindow(const wchar_t* /*title*/, int /*width*/, int /*height*/) {
        // No-op window creation code
        return true;
    }

    void CrossView::Impl::shutdown() {
        // No-op shutdown code
    }

} // namespace CrossViewer
