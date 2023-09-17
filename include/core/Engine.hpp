#pragma once

#include "core/gui/SystemWindow.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

struct Engine {
    explicit Engine(std::unique_ptr<SystemWindow> window);

    Engine(Engine&) = delete;
    Engine& operator=(Engine&) = delete;

    Engine(Engine&&) noexcept = delete;
    Engine& operator=(Engine&&) noexcept = delete;

    void run();

    ~Engine() = default;

private:
    std::unique_ptr<SystemWindow> window_;
};