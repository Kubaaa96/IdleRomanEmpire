#include "client/Application.hpp"

void Application::run() {
    engine_->run();

}
Application::Application()
    : window_(std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Idle Roman Empire")),
      engine_(std::make_unique<Engine>(std::move(window_))) {}
