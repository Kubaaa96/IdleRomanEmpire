#include "core/gui/SystemWindow.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

bool SystemWindow::isOpen() {
    return window_->isOpen();
}

void SystemWindow::processEvents() {

    sf::Event event;

    while (window_->pollEvent(event)) {
        try {
            process_sfml_events.at(event.type)(this, event);

        } catch (const std::out_of_range& exception) {
            spdlog::debug("Unhandled Event occuared in {}", exception.what());
        }
    }
}

void SystemWindow::display() {
    window_->display();
}

void SystemWindow::update() {
    state_machine_->nextState();
}

void SystemWindow::draw() {
    state_machine_->draw();
}

void SystemWindow::forwardEvent([[maybe_unused]] TranslatedEvent& event) {}

void SystemWindow::processSfmlResized(sf::Event& event) {
    fmt::print("Resized {} x {}\n", event.size.height, event.size.width);
}

void SystemWindow::processSfmlLostFocus([[maybe_unused]] sf::Event& event) {
    fmt::print("Lost Focus\n");
}

void SystemWindow::processSfmlGainedFocus([[maybe_unused]] sf::Event& event) {
    fmt::print("Gained Focus\n");
}

void SystemWindow::processSfmlMouseButtonPressed(sf::Event& event) {
    MouseButtonPressedEvent mouse_button_pressed_event;
    mouse_button_pressed_event.button = event.mouseButton.button;
    mouse_button_pressed_event.position = {static_cast<float>(event.mouseButton.x),
                                           static_cast<float>(event.mouseButton.y)};
    forwardEventWithPosition(mouse_button_pressed_event);
}

void SystemWindow::processSfmlMouseButtonReleased(sf::Event& event) {
    MouseButtonReleasedEvent mouse_button_released_event;
    mouse_button_released_event.button = event.mouseButton.button;
    mouse_button_released_event.position = {static_cast<float>(event.mouseButton.x),
                                            static_cast<float>(event.mouseButton.y)};
    forwardEventWithPosition(mouse_button_released_event);
}

void SystemWindow::processSfmlMouseMoved(sf::Event& event) {
    if (event.mouseMove.x == last_mouse_position_.x && event.mouseMove.y == last_mouse_position_.y) {
        return;
    }

    MouseMovedEvent mouse_moved_event;
    mouse_moved_event.position = {static_cast<float>(event.mouseMove.x),
                                  static_cast<float>(event.mouseMove.y)};
    last_mouse_position_ = {event.mouseMove.x, event.mouseMove.y};
    forwardEventWithPosition(mouse_moved_event);
}

void SystemWindow::processSfmlClosed([[maybe_unused]] sf::Event& event) {
    fmt::print("Closing\n");
    window_->close();
}
