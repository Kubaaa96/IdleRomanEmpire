#pragma once

#include "core/gui/widgets/Container.hpp"

struct Group :  Container {
    void add(std::unique_ptr<Widget> widget) override;

    void setPosition(const sf::Vector2f& position) override;

    void updateWidgets();
};
