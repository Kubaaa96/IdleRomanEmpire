#include "core/state/State.hpp"

State::State(sf::RenderTarget *render_target, bool replacing) : render_target_(render_target), replacing_(replacing) {}

void State::draw() {
    render_target_->clear();
    if(group_){
        group_->draw(render_target_);
    }
}

bool State::isReplacing() const {
    return replacing_;
}

std::unique_ptr<State> State::next() {
    return std::move(next_);
}

