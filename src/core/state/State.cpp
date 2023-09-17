#include "core/state/State.hpp"

State::State(sf::RenderTarget *renderTarget) : renderTarget_(renderTarget) {}

void State::draw() {
    renderTarget_->clear();
}

std::unique_ptr<State> State::next() {
    return std::move(next_);
}

