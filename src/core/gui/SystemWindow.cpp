#include "core/gui/SystemWindow.hpp"

#include <fmt/core.h>

void SystemWindow::display() {
    window_->display();
}

void SystemWindow::update() {
    window_->clear();
}

void SystemWindow::draw() {
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(320, 240);
    rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);

    window_->draw(rectangle);
}

bool SystemWindow::isOpen() {
    return window_->isOpen();
}
void SystemWindow::processEvents() {

    sf::Event event;

    while (window_->pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            fmt::print("Mouse button click location: {}, {}\n", event.mouseButton.x, event.mouseButton.y);
        }
        if (event.type == sf::Event::Closed) {
            window_->close();
        }
    }
}
