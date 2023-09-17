#include "core/gui/SystemWindow.hpp"

#include <fmt/core.h>

void SystemWindow::display() {
    window_->display();
}

void SystemWindow::update() {
    stateMachine_->nextState();
}

void SystemWindow::draw() {
    stateMachine_->draw();
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
