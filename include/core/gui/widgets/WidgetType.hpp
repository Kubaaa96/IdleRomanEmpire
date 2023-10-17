#pragma once

#include <string>
#include <atomic>

struct WidgetType
{
    WidgetType(const WidgetType&) = default;
    WidgetType& operator=(const WidgetType&) = default;

    WidgetType(WidgetType&&) = default;
    WidgetType& operator=(WidgetType&&) = default;

    ~WidgetType() = default;

    [[nodiscard]] uint64_t getIndex() const {
        return index_;
    }
    [[nodiscard]] std::string_view getName() const {
        return name_;
    }

    static WidgetType create(std::string_view name)
    {
        return { makeNextId(), name };
    }

private:
    uint64_t index_;
    std::string_view name_;

    WidgetType(uint64_t index, std::string_view name) : index_(index), name_(name) {};

    [[nodiscard]] static uint64_t makeNextId()
    {
        static std::atomic<uint64_t> nextId{ 0 };
        return nextId.fetch_add(1);
    }
};

