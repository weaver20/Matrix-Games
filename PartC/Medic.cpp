#include "Medic.h"

namespace mtm {


    Medic::Medic(units_t health, units_t ammo, units_t attack_range, units_t power) {

    }

    Character *Medic::clone() const {
        return nullptr;
    }

    bool Medic::canAttackThere(const GridPoint &source, const GridPoint &dest) const {
        // Medic cant Attack it self.
        // Must be inside attack range.
        return GridPoint::distance(source,dest) > 0 and GridPoint::distance(source,dest) <= kAttackRange;
    }

    AttackResult Medic::attackVictim(std::shared_ptr<Character> victim) {
        if (victim == nullptr) {
            throw IllegalTarget();
        }
        if(isFriend(victim)) {  // give Medicine!
            victim->acceptMedicine(getPower());
            ammo++; // the Game will decrement that ammo.
            return STILL_ALLIVE;
        }
        // victim is an enemy - Attack!
        if(isOutOfAmmo()) {
            throw OutOfAmmo();
        }
        AttackResult result = victim->getHit(getPower());
        return result;
    }
}