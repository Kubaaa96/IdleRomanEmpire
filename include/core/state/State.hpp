#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

struct State{
    State(sf::RenderTarget* renderTarget);

    virtual void draw();

    std::unique_ptr<State> next();

    virtual ~State() = default;

protected:
    sf::RenderTarget* renderTarget_;

    std::unique_ptr<State> next_;
};