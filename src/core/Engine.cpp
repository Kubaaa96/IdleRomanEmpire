#include "core/Engine.hpp"
#include <fmt/core.h>

Engine::Engine(std::unique_ptr<sf::RenderWindow> window) : window_(std::move(window)) {}


void Engine::run() {
    fmt::print("IRELib | Engine\n");

    while (window_->isOpen()) {
        sf::Event event;

        sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
        rectangle.setFillColor(sf::Color::Blue);
        rectangle.setPosition(320, 240);
        rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                fmt::print("Mouse button click location: {}, {}\n", event.mouseButton.x, event.mouseButton.y);
            }
            if (event.type == sf::Event::Closed) {
                window_->close();
            }
        }
        window_->clear(sf::Color::Black);
        window_->draw(rectangle);// Drawing our shape.
        window_->display();
    }
}
