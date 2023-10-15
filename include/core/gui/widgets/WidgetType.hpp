#pragma once

#include <string>
#include <atomic>

struct WidgetType
{
    [[nodiscard]] uint64_t getIndex() const {
        return _index;
    }
    [[nodiscard]] std::string_view getName() const {
        return _name;
    }

    static WidgetType create(std::string_view name)
    {
        return { makeNextId(), name };
    }

private:
    uint64_t _index;
    std::string_view _name;

    WidgetType(uint64_t index, std::string_view name) : _index(index), _name(name) {};

    [[nodiscard]] static uint64_t makeNextId()
    {
        static std::atomic<uint64_t> nextId{ 0 };
        return nextId.fetch_add(1);
    }
};

