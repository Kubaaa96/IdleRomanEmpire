#include "core/gui/widgets/Container.hpp"
#include "core/gui/widgets/WidgetType.hpp"

Container::Container(std::string_view name) : Widget(name) {}

void Container::add(std::unique_ptr<Widget> widget) {
    widget->setParent(this);
    widgets_.push_back(std::move(widget));
}

void Container::draw(sf::RenderTarget* target) {
    std::ranges::for_each(widgets_, [&target](const std::unique_ptr<Widget>& widget) {
        widget->draw(target);
    });
}

std::size_t Container::getWidgetsCount() const {
    return widgets_.size();
}

void Container::onEvent(MouseButtonPressedEvent& event) {
    forwardEventWithPosition(event);
}

void Container::onEvent(MouseButtonReleasedEvent& event) {
    Widget::onEvent(event);
}

void Container::onEvent(MouseMovedEvent& event) {
    Widget::onEvent(event);
}
