#include "client/state/GameState.hpp"
#include "core/gui/widgets/Button.hpp"
#include <iostream>
GameState::GameState(sf::RenderTarget *renderTarget, bool replacing) : State(renderTarget, replacing) {
    auto button = std::make_unique<Button>();
    auto button2 = std::make_unique<Button>();


    group_ = std::make_unique<Group>();

    auto type1 = button->getType();
    std::cout << type1.getName() << " " << type1.getIndex() << "\n";
    auto type2 = button2->getType();
    std::cout << type2.getName() << " " << type2.getIndex() << "\n";
    group_->add(std::move(button));
    group_->add(std::move(button2));
    group_->setPosition({120, 120});
}

void GameState::draw() {
    const auto current_viewport_size = static_cast<sf::Vector2f>(render_target_->getSize());
    group_->setSize(current_viewport_size);
    State::draw();
}
