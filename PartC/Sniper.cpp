#include "Sniper.h"

namespace mtm {


    Sniper::Sniper(units_t health, units_t ammo, units_t attack_range, units_t power) {

    }

    Character *Sniper::clone() const {
        return nullptr;
    }

    bool Sniper::isInAttackRange(GridPoint &source, GridPoint &dest) const {
        return false;
    }

    units_t Sniper::getPower() const {
        return Character::getPower();
    }

    void Sniper::attackSuccess() {
        Character::attackSuccess();
    }
}