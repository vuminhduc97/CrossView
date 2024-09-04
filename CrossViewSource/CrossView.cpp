#include "CrossView.h"

// Include platform-specific headers
#ifdef _WIN32
#include "CrossViewWin32.h"

#elif defined(__linux__)
#include "CrossViewX11.h"

#elif defined(__APPLE__)
#include "CrossViewMac.h"

#elif defined(__XBOX__)
#include "CrossViewXbox.h"

#elif defined(__PS5__)
#include "CrossViewPS5.h"

#elif defined(HEADLESS)
#include "CrossViewNoop.h"

#else
#include "CrossViewNoop.h"

#endif

namespace CrossViewer {

    std::unique_ptr<CrossView> CrossView::createCrossView() 
    {

#ifdef _WIN32
        return std::make_unique<CrossViewWin32>();

#elif defined(__linux__)
        return std::make_unique<CrossViewX11>();

#elif defined(__APPLE__)
        return std::make_unique<CrossViewMac>();

#elif defined(__XBOX__)
        return std::make_unique<CrossViewXbox>();

#elif defined(__PS5__)
        return std::make_unique<CrossViewPS5>();

#elif defined(HEADLESS)
        return std::make_unique<CrossViewNoop>();

#else
        return std::make_unique<CrossViewNoop>();

#endif

    }

} // namespace CrossViewer
