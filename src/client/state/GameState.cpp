#include "client/state/GameState.hpp"
#include "core/gui/widgets/Button.hpp"
#include <iostream>
GameState::GameState(sf::RenderTarget *renderTarget, bool replacing) : State(renderTarget, replacing) {
    auto button = std::make_unique<Button>();

    group_ = std::make_unique<Group>();
    group_->add(std::move(button));
    group_->setPosition({120, 120});
}

void GameState::draw() {
    const auto current_viewport_size = static_cast<sf::Vector2f>(render_target_->getSize());
    group_->setSize(current_viewport_size);
    State::draw();
}
