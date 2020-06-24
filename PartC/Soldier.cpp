#include "Soldier.h"

namespace mtm {


    Soldier::Soldier(units_t health, units_t ammo, units_t attack_range, units_t power) {

    }

    Character *Soldier::clone() const {
        return nullptr;
    }

    bool Soldier::isInAttackRange(GridPoint &source, GridPoint &dest) const {
        return false;
    }
}