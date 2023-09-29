#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <fmt/core.h>
struct Container;

struct Widget {
    explicit Widget() = default;

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

    // TODO Clone Widget?
    // TODO relative methods for move, rotate scale
    // TODO gen ptr to widget by clicking on it ?
protected:
    sf::Vector2f size_{0.F, 0.F};
    sf::Vector2f position_{0.F, 0.F};
    sf::Vector2f local_position_{0.F, 0.F};
    // TODO rotation
    // TODO scale

    sf::Vector2f origin_{0.F, 0.F};
    // TODO visibility
    // TODO enable

    Container* parent_ = nullptr;
};