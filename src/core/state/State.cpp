#include "core/state/State.hpp"

State::State(sf::RenderTarget *renderTarget, bool replacing) : renderTarget_(renderTarget), replacing_(replacing) {}

void State::draw() {
    renderTarget_->clear();
}

bool State::isReplacing() const {
    return replacing_;
}

std::unique_ptr<State> State::next() {
    return std::move(next_);
}
