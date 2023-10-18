#pragma once

#include "core/gui/widgets/Widget.hpp"

#include <gmock/gmock.h>

struct WidgetMock : Widget {
    WidgetMock() : Widget("WidgetMock") {}
    MOCK_METHOD(void, draw, (sf::RenderTarget* target), (override));
};