#include "core/gui/widgets/Button.hpp"

Button::Button() : ClickableWidget("Button") {
    rectangle_shape.setSize(default_size);
    rectangle_shape.setFillColor(sf::Color::Red);
}

void Button::draw(sf::RenderTarget *target) {
    target->draw(rectangle_shape);
}

void Button::updateWidget() {
    rectangle_shape.setPosition(position_);
}
