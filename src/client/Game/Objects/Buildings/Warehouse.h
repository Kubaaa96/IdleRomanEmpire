#ifndef IRE_WAREHOUSE_H
#define IRE_WAREHOUSE_H

#include "core/world/objects/Building.h"

namespace ire::client::objects
{

    struct Warehouse : core::world::objects::Building
    {

        Warehouse();
        void initializeOverlay() override;
        void updatePlannedOverlay(sf::Vector2i mousePosition) override;
        void setupOrderedOverlay(sf::Vector2i clickPosition) override;

    protected:

        void setupInProductionOverlay() override;
        void setupIdleOverlay() override;
    };

}

#endif //!IRE_WAREHOUSE_H