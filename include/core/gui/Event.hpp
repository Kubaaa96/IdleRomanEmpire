#pragma once

#include <SFML/Window/Event.hpp>

struct TranslatedEvent {
    bool handled{false};
};

struct ClosedEvent : TranslatedEvent {};

struct ResizedEvent : TranslatedEvent {
    sf::Vector2f new_size;
};

struct MouseButtonPressedEvent : TranslatedEvent {
    sf::Mouse::Button button;
    sf::Vector2f position;
};

struct MouseButtonReleasedEvent : TranslatedEvent {
    sf::Mouse::Button button;
    sf::Vector2f position;
};

struct MouseMovedEvent : TranslatedEvent {
    sf::Vector2f position;
};

struct GainedFocusEvent : TranslatedEvent {};

struct LostFocusEvent : TranslatedEvent {};