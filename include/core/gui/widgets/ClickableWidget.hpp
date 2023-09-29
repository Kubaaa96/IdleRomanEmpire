#pragma once

#include "core/gui/widgets/Widget.hpp"

struct ClickableWidget : Widget {

    void setSize(const sf::Vector2f& size) override;

    void setPosition(const sf::Vector2f& position) override;

    virtual void updateWidget() = 0;
};