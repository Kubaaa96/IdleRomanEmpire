#include "client/state/GameState.hpp"
#include "core/gui/widgets/Button.hpp"

GameState::GameState(sf::RenderTarget *renderTarget, bool replacing) : State(renderTarget, replacing) {}

void GameState::draw() {
    auto button = std::make_unique<Button>();

    const auto current_viewport_size = static_cast<sf::Vector2f>(render_target_->getSize());
    group_ = std::make_unique<Group>(current_viewport_size);
    group_->add(std::move(button));

    State::draw();

//    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
//    rectangle.setFillColor(sf::Color::Blue);
//    rectangle.setPosition(320, 240);
//
//    render_target_->draw(rectangle);
}
