#include "core/Engine.hpp"

#include <spdlog/spdlog.h>

Engine::Engine(std::unique_ptr<SystemWindow> window) : window_(std::move(window)) {}

void Engine::run() {

    spdlog::debug("IRELib | Engine");

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
