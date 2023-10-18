#pragma once

#include "core/gui/widgets/Widget.hpp"

struct Container : Widget {
    explicit Container(std::string_view name);
    virtual void add(std::unique_ptr<Widget> widget);
    void draw(sf::RenderTarget* target) override;

    [[nodiscard]] std::size_t getWidgetsCount() const;
protected:
    std::vector<std::unique_ptr<Widget>> widgets_;
};
