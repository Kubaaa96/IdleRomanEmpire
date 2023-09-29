#pragma once

#include "core/state/State.hpp"

struct GameState : State{

    explicit GameState(sf::RenderTarget* render_target, bool replacing);

    void draw() override;
};

