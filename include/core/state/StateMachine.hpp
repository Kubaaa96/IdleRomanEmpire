#pragma once

#include "core/state/State.hpp"

#include <memory>
#include <stack>

struct StateMachine{
    void run(std::unique_ptr<State> state);

    void nextState();

    void draw();

private:
    std::stack<std::unique_ptr<State>> states_;
};