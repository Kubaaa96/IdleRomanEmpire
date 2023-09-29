#include "core/gui/widgets/Group.hpp"

void Group::updateWidgets() {
    std::ranges::for_each(widgets_, [&position_ = position_](const std::unique_ptr<Widget>& widget) {
        widget->setOrigin(position_);
        widget->setLocalPosition(widget->getPosition());
    });
}

void Group::add(std::unique_ptr<Widget> widget) {
    Container::add(std::move(widget));
    updateWidgets();
}

void Group::setPosition(const sf::Vector2f& position) {
    Widget::setPosition(position);
    updateWidgets();
}
