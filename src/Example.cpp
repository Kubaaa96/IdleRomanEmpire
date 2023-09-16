#include "Example.hpp"
#include <SFML/Graphics.hpp>

float Example::getXOfRectangle() {
    const sf::RectangleShape rectangle(sf::Vector2f(128.0f,128.0f));
    return rectangle.getSize().x;
}
