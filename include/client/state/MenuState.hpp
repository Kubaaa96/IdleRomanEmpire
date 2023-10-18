#pragma once

#include "core/state/State.hpp"

struct MenuState : State{

    explicit MenuState(sf::RenderTarget* render_target, bool replacing);

    void draw() override;
};