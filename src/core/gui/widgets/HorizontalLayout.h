#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H

#include "BoxLayout.h"

namespace ire::core::gui
{
    struct HorizontalLayout : BoxLayout
    {
        HorizontalLayout(const sf::Vector2f& size);

        static std::unique_ptr<HorizontalLayout> create(const sf::Vector2f& size);

        static const WidgetType m_type;
        const WidgetType getType() const override
        {
            return m_type;
        }

    protected:
        void updateWidgets() override;
    };
}

#endif // !HORIZONTALLAYOUT_H