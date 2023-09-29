#pragma once

#include "core/gui/widgets/ClickableWidget.hpp"

#include <SFML/Graphics.hpp>

struct Button : ClickableWidget{
    Button();

    void updateWidget() override;

    void draw(sf::RenderTarget *target) override;

private:
    sf::RectangleShape rectangle_shape;
    const sf::Vector2f default_size{320, 120};
};