#pragma once

#include <core/gui/Event.hpp>

#include <functional>
#include <utility>

struct AnyEventListener{
    AnyEventListener() = default;

    AnyEventListener(const AnyEventListener&) = delete;
    AnyEventListener(AnyEventListener&&) = delete;

    AnyEventListener& operator=(const AnyEventListener&) = delete;
    AnyEventListener& operator=(AnyEventListener&&) = delete;

    virtual ~AnyEventListener() = default;

    virtual void onEvent(void* typeErasedEvent) = 0;
};

template<typename EventT, typename FuncT>
struct EventListener : AnyEventListener {
    explicit EventListener(FuncT func) : func_(std::move(func)) {}

    void onEvent(void* event) {
        EventT& ev = *(std::bit_cast<EventT*>(event));
        std::invoke(func_, ev);
    }

private:
    FuncT func_;
};