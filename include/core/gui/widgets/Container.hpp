#pragma once

#include "core/gui/widgets/Widget.hpp"

struct Container : Widget {
    explicit Container(std::string_view name);
    virtual void add(std::unique_ptr<Widget> widget);
    void draw(sf::RenderTarget* target) override;

    [[nodiscard]] std::size_t getWidgetsCount() const;

    void onEvent(MouseButtonPressedEvent& event) override;
    void onEvent(MouseButtonReleasedEvent& event) override;
    void onEvent(MouseMovedEvent& event) override;

protected:
    std::vector<std::unique_ptr<Widget>> widgets_;

private:
    template<typename EventT>
    void forwardEventWithPosition(EventT& event){
        for(auto& widget : widgets_){
            if(widget->getClientBounds().contains(event.position)){
                widget->onEvent(event);
                if(event.handled){
                    break;
                }
            }
        }
    }
};
