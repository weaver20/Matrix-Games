#include "Medic.h"

namespace mtm {


    Medic::Medic(units_t health, units_t ammo, units_t attack_range, units_t power) {

    }

    Character *Medic::clone() const {
        return nullptr;
    }

    bool Medic::isInAttackRange(GridPoint &source, GridPoint &dest) const {
        return false;
    }
}