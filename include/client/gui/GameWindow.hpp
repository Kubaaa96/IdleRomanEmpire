#pragma once

#include "client/state/MenuState.hpp"
#include "client/state/GameState.hpp"

#include "core/gui/SystemWindow.hpp"

struct GameWindow : SystemWindow{
    template<typename... T>
    explicit GameWindow(T&&... args) : SystemWindow(std::forward<T>(args)...){
        stateMachine_->run(std::make_unique<GameState>(window_.get(), true));
    }
};