#include "client/state/GameState.hpp"
#include "core/gui/widgets/Button.hpp"

GameState::GameState(sf::RenderTarget *renderTarget, bool replacing) : State(renderTarget, replacing) {}

void GameState::draw() {
    auto button = std::make_unique<Button>();

    const auto current_viewport_size = static_cast<sf::Vector2f>(render_target_->getSize());
    group_ = std::make_unique<Group>();
    group_->setSize(current_viewport_size);
    group_->add(std::move(button));
    group_->setPosition({120, 120});

    State::draw();
}
