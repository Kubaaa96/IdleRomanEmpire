#include "core/state/StateMachine.hpp"

void StateMachine::run(std::unique_ptr<State> state) {
    states_.push(std::move(state));
}

void StateMachine::nextState() {
    if (auto temp_state = states_.top()->next(); !states_.empty() && temp_state != nullptr) {
        states_.pop();
        states_.push(std::move(temp_state));
    }
}

void StateMachine::draw() {
    states_.top()->draw();
}
