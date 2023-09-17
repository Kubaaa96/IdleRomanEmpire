#pragma once

#include <SFML/Graphics.hpp>

#include <memory>

struct Engine{
    explicit Engine(std::unique_ptr<sf::RenderWindow> window);
    void run();
private:
    std::unique_ptr<sf::RenderWindow> window_;
};