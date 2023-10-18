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
