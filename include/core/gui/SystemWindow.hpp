#pragma once

#include "core/state/StateMachine.hpp"
#include "core/state/State.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

struct SystemWindow {

    template<typename... T>
    explicit SystemWindow(T&&... args)
        : window_(std::make_unique<sf::RenderWindow>(std::forward<T>(args)...)) {
    }

    SystemWindow(const SystemWindow&) = delete;
    SystemWindow& operator=(SystemWindow&) = delete;

    SystemWindow(const SystemWindow&&) = delete;
    SystemWindow& operator=(SystemWindow&&) = delete;

    ~SystemWindow() = default;

    bool isOpen();

    void processEvents();

    void display();

    void update();

    void draw();

protected:
    std::unique_ptr<sf::RenderWindow> window_;
    std::unique_ptr<StateMachine> state_machine_{std::make_unique<StateMachine>()};
};