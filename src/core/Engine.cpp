#include "core/Engine.hpp"
#include <fmt/core.h>

Engine::Engine(std::unique_ptr<SystemWindow> window) : window_(std::move(window)) {}


void Engine::run() {
    fmt::print("IRELib | Engine\n");

    for (;;) {
        window_->processEvents();

        if (!window_->isOpen()) {
            break;
        }

        window_->update();
        window_->draw();
        window_->display();
    }
}
