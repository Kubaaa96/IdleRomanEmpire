#pragma once

#include "core/gui/widgets/Group.hpp"
#include "core/gui/Event.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

struct State{
    State(sf::RenderTarget* render_target, bool replacing);

    State(const State&) = delete;
    State& operator=(State&) = delete;

    State(const State&&) = delete;
    State& operator=(State&&) = delete;

    virtual void draw();

    std::unique_ptr<State> next();

    [[nodiscard]] bool isReplacing() const;

    template<typename EventT>
    void forwardEventWithPosition(EventT& event){
        if(group_->getClientBounds().contains(event.position)){
            group_->onEvent(event);
        }
    }

    virtual ~State() = default;

protected:
    sf::RenderTarget* render_target_;

    std::unique_ptr<State> next_;

    std::unique_ptr<Group> group_;

    bool replacing_;
};