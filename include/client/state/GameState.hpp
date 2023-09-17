#pragma once

#include "core/state/State.hpp"

struct GameState : State{

    explicit GameState(sf::RenderTarget* renderTarget, bool replacing);

    void draw() override;
};