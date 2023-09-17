#include "client/state/MenuState.hpp"

MenuState::MenuState(sf::RenderTarget *renderTarget) : State(renderTarget) {}

void MenuState::draw() {
    State::draw();

    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(320, 240);

    renderTarget_->draw(rectangle);
}
