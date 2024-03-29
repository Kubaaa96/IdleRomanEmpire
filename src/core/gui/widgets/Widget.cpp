#include "core/gui/widgets/Widget.hpp"

Widget::Widget(std::string_view name) : type_(WidgetType::create(name)) {}

void Widget::setPosition(const sf::Vector2f& position) {
    position_ = position;
}

sf::Vector2f Widget::getPosition() const {
    return position_;
}

void Widget::setOrigin(sf::Vector2f origin) {
    origin_ = origin;
}

sf::Vector2f Widget::getOrigin() const {
    return origin_;
}

void Widget::setParent(Container *parent) {
    if(parent_ == parent){
        return;
    }
    parent_ = parent;
}

Container* Widget::getParent() const {
    return parent_;
}

void Widget::setSize(const sf::Vector2f& size) {
    size_ = size;
}

sf::Vector2f Widget::getSize() const {
    return size_;
}
void Widget::setLocalPosition(const sf::Vector2f& local_position) {
    local_position_ = local_position;
    setPosition(origin_ + local_position);
}

sf::Vector2f Widget::getLocalPosition() const {
    return local_position_;
}

WidgetType Widget::getType() const {
    return type_;
}
