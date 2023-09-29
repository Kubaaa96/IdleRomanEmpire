#include "core/gui/widgets/Widget.hpp"

#include "core/gui/widgets/ClickableWidget.hpp"


void ClickableWidget::setSize(const sf::Vector2f& size) {
    Widget::setSize(size);
    updateWidget();
}
void ClickableWidget::setPosition(const sf::Vector2f& position) {
    Widget::setPosition(position);
    updateWidget();
}
