#include "client/Application.hpp"

#include <spdlog/spdlog.h>

int main(){

    spdlog::set_level(spdlog::level::debug);

    auto app = std::make_unique<Application>();
    app->run();
}
