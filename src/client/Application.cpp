#include "client/Application.hpp"

void Application::run() {
    engine_->run();

}
Application::Application()
    : window_(std::make_unique<GameWindow>(sf::VideoMode(window_width_, window_height_), "Idle Roman Empire")),
      engine_(std::make_unique<Engine>(std::move(window_))) {}
