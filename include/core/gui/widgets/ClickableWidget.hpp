#pragma once

#include "core/gui/widgets/Widget.hpp"

struct ClickableWidget : Widget {

    explicit ClickableWidget(std::string_view name);

    void setSize(const sf::Vector2f& size) override;

    void setPosition(const sf::Vector2f& position) override;

    virtual void updateWidget() = 0;
};