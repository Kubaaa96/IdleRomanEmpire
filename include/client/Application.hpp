#pragma once

#include "core/Engine.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

struct Application{
    explicit Application();
    void run();
    ~Application() = default;

private:
    std::unique_ptr<sf::RenderWindow> window_;
    std::unique_ptr<Engine> engine_;
};