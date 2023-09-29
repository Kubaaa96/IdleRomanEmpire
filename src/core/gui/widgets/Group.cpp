#include "core/gui/widgets/Group.hpp"

Group::Group(const sf::Vector2f& size) {
    setSize(size);
}
void Group::updateWidgets() {
    std::ranges::for_each(widgets_, [&position_ = position_](const std::unique_ptr<Widget>& widget){
        widget->setOrigin(position_);
        widget->setLocalPosition(widget->getPosition());
    });
}
void Group::add(std::unique_ptr<Widget> widget) {
    Container::add(std::move(widget));
    updateWidgets();
}
