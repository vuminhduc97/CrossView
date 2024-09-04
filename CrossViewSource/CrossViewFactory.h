#pragma once

#include <memory>
#include "CrossView.h"

namespace CrossViewer {

    class CrossViewFactory {
    public:
        virtual ~CrossViewFactory() = default;
        virtual std::unique_ptr<CrossView> create() const = 0;
    };

} // namespace CrossViewer
