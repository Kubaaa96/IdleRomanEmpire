#include "client/Application.hpp"

int main(){
    auto app = std::make_unique<Application>();
    app->run();
}
