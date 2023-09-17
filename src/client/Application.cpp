#include "client/Application.hpp"

void Application::run() {
    engine_->run();

}
Application::Application()
    : window_(std::make_unique<SystemWindow>(sf::VideoMode(window_width, window_height), "Idle Roman Empire")),
      engine_(std::make_unique<Engine>(std::move(window_))) {}
