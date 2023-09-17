#pragma once

#include "client/gui/GameWindow.hpp"

#include "core/Engine.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

struct Application{
    explicit Application();

    Application(Application&) = delete;
    Application& operator=(Application&) = delete;

    Application(Application&& application) noexcept = delete;
    Application& operator=(Application&&) noexcept = delete;

    void run();

    ~Application() = default;

private:
    const unsigned int window_width{1920};
    const unsigned int window_height{1080};

    std::unique_ptr<GameWindow> window_;
    std::unique_ptr<Engine> engine_;
};