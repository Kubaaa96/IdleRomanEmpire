#pragma once

#include "core/gui/widgets/Widget.hpp"

#include <SFML/Graphics.hpp>

struct Button : Widget{
    Button();

    void draw(sf::RenderTarget *target) override;

private:
    sf::RectangleShape rectangle_shape;
    const sf::Vector2f default_size{320, 120};
};