#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

struct State{
    State(sf::RenderTarget* renderTarget, bool replacing);

    State(const State&) = delete;
    State& operator=(State&) = delete;

    State(const State&&) = delete;
    State& operator=(State&&) = delete;

    virtual void draw();

    std::unique_ptr<State> next();

    [[nodiscard]] bool isReplacing() const;

    virtual ~State() = default;

protected:
    sf::RenderTarget* renderTarget_;

    std::unique_ptr<State> next_;

    bool replacing_;
};