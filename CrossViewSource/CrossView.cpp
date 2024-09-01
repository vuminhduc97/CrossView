#include "CrossView.h"

namespace CrossViewer {

    class CROSSVIEW_API CrossView::Impl {
    public:
        bool init() { return true; }
        bool createWindow(const wchar_t* title, int width, int height) { return true; }
        void shutdown() {}
    };

    std::unique_ptr<CrossView> CrossView::createCrossView() {
        auto view = std::make_unique<CrossView>();
        view->impl = std::make_unique<Impl>();
        return view;
    }

    CrossView::CrossView() = default;
    CrossView::~CrossView() = default;

    bool CrossView::init() {
        if (impl) {
            return impl->init();
        }
        return false;
    }

    bool CrossView::createWindow(const wchar_t* title, int width, int height) {
        if (impl) {
            return impl->createWindow(title, width, height);
        }
        return false;
    }

    void CrossView::shutdown() {
        if (impl) {
            impl->shutdown();
        }
    }

} // namespace CrossViewer
