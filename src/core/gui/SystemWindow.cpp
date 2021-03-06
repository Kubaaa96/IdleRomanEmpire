#include "SystemWindow.h"

namespace ire::core::gui {

    [[nodiscard]] sf::RenderTarget& SystemWindow::getRenderTarget()
    {
        return m_window;
    }

    [[nodiscard]] bool SystemWindow::isOpen() const
    {
        return m_window.isOpen();
    }

    void SystemWindow::processEvents()
    {
        TimePoint timestamp = TimePoint::now();
        sf::Event ev;
        while (m_window.pollEvent(ev))
        {
            processSfmlEvent(ev, timestamp);
        }
    }

    void SystemWindow::close()
    {
        m_window.close();
    }

    void SystemWindow::display()
    {     
        m_window.display();
    }

    void SystemWindow::update()
    {
        m_stateMachine.nextState();
    }

    void SystemWindow::draw()
    {
        m_stateMachine.draw();
    }

    void SystemWindow::setRootGroup(Group& group)
    {
        m_rootGroup = &group;
    }

    void SystemWindow::processSfmlEvent(sf::Event& ev, TimePoint timestamp)
    {
        switch (ev.type)
        {
        case sf::Event::EventType::Closed:
            processSfmlClosedEvent(ev, timestamp);
            break;

        case sf::Event::EventType::MouseButtonPressed:
            processSfmlMouseButtonPressedEvent(ev, timestamp);
            break;

        case sf::Event::EventType::MouseButtonReleased:
            processSfmlMouseButtonReleasedEvent(ev, timestamp);
            break;

        case sf::Event::EventType::MouseMoved:
            processSfmlMouseMovedEvent(ev, timestamp);
            break;

        case sf::Event::EventType::TextEntered:
            processSfmlTextEnteredEvent(ev, timestamp);
            break;

        case sf::Event::EventType::KeyPressed:
            processSfmlKeybordPressedEvent(ev, timestamp);
            break;

        case sf::Event::EventType::KeyReleased:
            processSfmlKeybordReleasedEvent(ev, timestamp);
            break;
        }
    }

    void SystemWindow::processSfmlClosedEvent(sf::Event& ev, TimePoint timestamp)
    {
        WindowClosedEvent translatedEv{};
        emitEvent<WindowClosedEvent>(translatedEv);

        if (!translatedEv.cancel)
        {
            close();
        }
    }

    void SystemWindow::processSfmlMouseButtonPressedEvent(sf::Event& ev, TimePoint timestamp)
    {
        MouseButtonDownEvent translatedEv{};
        translatedEv.timestamp = timestamp;
        translatedEv.button = ev.mouseButton.button;
        translatedEv.position = sf::Vector2f(
            static_cast<float>(ev.mouseButton.x), 
            static_cast<float>(ev.mouseButton.y));

        forwardEventWithPosition(translatedEv);
    }

    void SystemWindow::processSfmlMouseButtonReleasedEvent(sf::Event& ev, TimePoint timestamp)
    {
        MouseButtonUpEvent translatedEv{};
        translatedEv.timestamp = timestamp;
        translatedEv.button = ev.mouseButton.button;
        translatedEv.position = sf::Vector2f(
            static_cast<float>(ev.mouseButton.x),
            static_cast<float>(ev.mouseButton.y));

        forwardEventWithPosition(translatedEv);
    }

    void SystemWindow::processSfmlMouseMovedEvent(sf::Event& ev, TimePoint timestamp)
    {
        if (ev.mouseMove.x == m_lastMousePosition.x
            && ev.mouseMove.y == m_lastMousePosition.y)
        {
            // We prevent unneccesary MouseMoved events.
            return;
        }

        MouseMovedEvent translatedEv{};
        translatedEv.timestamp = timestamp;
        translatedEv.position = sf::Vector2f(
            static_cast<float>(ev.mouseMove.x),
            static_cast<float>(ev.mouseMove.y));
        m_lastMousePosition = { ev.mouseMove.x, ev.mouseMove.y };

        forwardEventWithPosition(translatedEv);
    }

    void SystemWindow::setActiveWidget(Widget& widget)
    {
        if (m_activeWidget != nullptr && m_activeWidget != &widget)
        {
            m_activeWidget->onStoppedBeingActive();
        }

        m_activeWidget = &widget;
    }

    const Widget* SystemWindow::getActiveWidget() const
    {
        return m_activeWidget;
    }

    void SystemWindow::resetActiveWidget(Widget& widget)
    {
        if (m_activeWidget == &widget)
        {
            m_activeWidget = nullptr;

            // We emit mouse moved here so that the thing
            // that didn't receive the previous event
            // because it was intercepted.
            reemitLastMouseMoved();
        }
    }

    void SystemWindow::reemitLastMouseMoved()
    {
        MouseMovedEvent translatedEv{};
        translatedEv.timestamp = TimePoint::now();
        translatedEv.position = sf::Vector2f(m_lastMousePosition);
        forwardEventWithPosition(translatedEv);
    }

    void SystemWindow::processSfmlTextEnteredEvent(sf::Event& ev, TimePoint timestamp)
    {
        TextEnteredEvent translatedEv{};
        translatedEv.timestamp = TimePoint::now();
        translatedEv.character = ev.text.unicode;

        forwardEvent(translatedEv);
    }

    void SystemWindow::processSfmlKeybordPressedEvent(sf::Event& ev, TimePoint timestamp)
    {
        KeyDownEvent translatedEv{};
        translatedEv.timestamp = TimePoint::now();
        translatedEv.key = ev.key.code;
        translatedEv.alt = ev.key.alt;
        translatedEv.control = ev.key.control;
        translatedEv.shift = ev.key.shift;
        translatedEv.system = ev.key.system;
        forwardEvent(translatedEv);
    }

    void SystemWindow::processSfmlKeybordReleasedEvent(sf::Event& ev, TimePoint timestamp)
    {
        KeyUpEvent translatedEv{};
        translatedEv.timestamp = TimePoint::now();
        translatedEv.key = ev.key.code;
        translatedEv.alt = ev.key.alt;
        translatedEv.control = ev.key.control;
        translatedEv.shift = ev.key.shift;
        translatedEv.system = ev.key.system;
        forwardEvent(translatedEv);
    }

}