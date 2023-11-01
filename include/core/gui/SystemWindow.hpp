#pragma once

#include "core/state/StateMachine.hpp"
//#include "core/state/State.hpp"


#include <SFML/Graphics.hpp>

#include <memory>
#include <map>
#include <functional>

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

private:
    template<typename EventT>
    void forwardEventWithPosition(EventT& event){
        if(isOpen()){
            state_machine_->forwardEventWithPosition(event);
        }
    }
    void forwardEvent(TranslatedEvent& event);

    void processSfmlResized(sf::Event& event);
    void processSfmlLostFocus(sf::Event& event);
    void processSfmlGainedFocus(sf::Event& event);
    void processSfmlMouseButtonPressed(sf::Event& event);
    void processSfmlMouseButtonReleased(sf::Event& event);
    void processSfmlMouseMoved(sf::Event& event);
    void processSfmlClosed(sf::Event& event);

    std::map<sf::Event::EventType, std::function<void(SystemWindow*, sf::Event&)>> process_sfml_events{
            {sf::Event::Closed, &SystemWindow::processSfmlClosed},
            {sf::Event::Resized, &SystemWindow::processSfmlResized},
            {sf::Event::MouseButtonPressed, &SystemWindow::processSfmlMouseButtonPressed},
            {sf::Event::MouseButtonReleased, &SystemWindow::processSfmlMouseButtonReleased},
            {sf::Event::MouseMoved, &SystemWindow::processSfmlMouseMoved},
            {sf::Event::GainedFocus, &SystemWindow::processSfmlGainedFocus},
            {sf::Event::LostFocus, &SystemWindow::processSfmlLostFocus},

    };
    sf::Vector2i last_mouse_position_;
};