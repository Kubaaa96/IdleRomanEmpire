#pragma once

#include "core/gui/widgets/WidgetType.hpp"

#include <SFML/Graphics.hpp>

#include <memory>
#include <fmt/core.h>

struct Container;
struct WidgetType;

struct Widget {
    explicit Widget(std::string_view name);

    Widget(const Widget&) = delete;
    Widget& operator=(const Widget&) = delete;

    Widget(Widget&&) noexcept = default;

    Widget& operator=(Widget&&) noexcept = default;

    virtual ~Widget() = default;

    virtual void draw(sf::RenderTarget* target) = 0;

    virtual void setSize(const sf::Vector2f& size);
    [[nodiscard]] sf::Vector2f getSize() const;

    virtual void setPosition(const sf::Vector2f& position);
    [[nodiscard]] sf::Vector2f getPosition() const;

    void setLocalPosition(const sf::Vector2f& localPosition);
    [[nodiscard]] sf::Vector2f getLocalPosition() const;

    void setOrigin(sf::Vector2f origin);
    [[nodiscard]] sf::Vector2f getOrigin() const;

    void setParent(Container* parent);
    [[nodiscard]] Container* getParent() const;

    [[nodiscard]] virtual WidgetType getType() const;

protected:
    sf::Vector2f size_{0.F, 0.F};
    sf::Vector2f position_{0.F, 0.F};
    sf::Vector2f local_position_{0.F, 0.F};

    sf::Vector2f origin_{0.F, 0.F};

    Container* parent_ = nullptr;
    const WidgetType type_;
};