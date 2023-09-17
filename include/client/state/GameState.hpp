#pragma once

#include "core/state/State.hpp"

struct GameState : State{

    explicit GameState(sf::RenderTarget* renderTarget);

    void draw() override;
};