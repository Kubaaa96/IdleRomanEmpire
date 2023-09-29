#pragma once

#include "core/gui/widgets/Container.hpp"

struct Group :  Container {
    Group(const sf::Vector2f& size);

    void add(std::unique_ptr<Widget> widget) override;

    void updateWidgets();
};
