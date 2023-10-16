#pragma once

#include "core/gui/widgets/Widget.hpp"

struct Container : Widget {
    explicit Container(std::string_view name);

    virtual void add(std::unique_ptr<Widget> widget);
    // TODO connect two containers
    // TODO remove by name and return bool? or remove by giving ptr ? depends what will be easier to get from widget after clicking
    // TODO remove all widgets and return bool
    void draw(sf::RenderTarget* target) override;
    // TODO Widget type?
    // TODO get ptr to widget by index
    // TODO get ptr to widget by name
    // TODO Release widget by index
    // TODO Release widget by name
    // TODO Clone whole container
    [[nodiscard]] std::size_t getWidgetsSize() const;
protected:
    std::vector<std::unique_ptr<Widget>> widgets_;
};