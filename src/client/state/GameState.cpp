#include "client/state/GameState.hpp"

GameState::GameState(sf::RenderTarget *renderTarget) : State(renderTarget) {}

void GameState::draw() {
    State::draw();

    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(320, 240);

    renderTarget_->draw(rectangle);
}
