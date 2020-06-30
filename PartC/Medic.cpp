#include "Medic.h"
#define MEDIC_MOVE_RANGE 5
#define MEDIC_RELOAD 5

namespace mtm {


    Medic::Medic(Team team, units_t health, units_t ammo, units_t attack_range, units_t power) :
            Character(team,health,ammo,attack_range,power,MEDIC_MOVE_RANGE,MEDIC_RELOAD)
    {}

    Character *Medic::clone() const {
        return new Medic(*this);
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