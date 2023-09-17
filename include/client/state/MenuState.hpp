#pragma once

#include "core/state/State.hpp"

struct MenuState : State{

    explicit MenuState(sf::RenderTarget* renderTarget);

    void draw() override;
};