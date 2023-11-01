#pragma once

#include "core/gui/EventListener.hpp"
#include "core/gui/Event.hpp"

#include <typeindex>
#include <map>
#include <functional>
#include <memory>

struct EventEmitter{

    EventEmitter() = default;

    EventEmitter(const EventEmitter&) = delete;
    EventEmitter(EventEmitter&&) = delete;

    EventEmitter& operator=(const EventEmitter&) = delete;
    EventEmitter& operator=(EventEmitter&&) = delete;

    ~EventEmitter() = default;

    template<typename EventT, typename FuncT>
    void addEventListener(FuncT func){
        using DecayedFuncT = std::remove_reference_t<FuncT>;
        auto listener = std::make_unique<EventListener<EventT, DecayedFuncT>>(std::forward<FuncT>(func));
        auto type = eventType<EventT>();
        listeners.emplace(type, std::move(listener));
    }

    template<typename EventT>
    void emitEvent(EventT event){
        auto type = eventType<EventT>();
        auto [begin, end] = listeners.equal_range(type);
        while (begin != end && !event.handled){
            begin->second->onEvent(std::bit_cast<void *>(&event));
            ++begin;
        }
    }

private:
    std::multimap<std::type_index, std::unique_ptr<AnyEventListener>> listeners;

    template<typename EventT>
    std::type_index eventType(){
        return std::type_index(typeid(EventT));
    }
};