#include "Medic.h"
#define MEDIC_MOVE_RANGE 5
#define MEDIC_RELOAD 5

namespace mtm {


    Medic::Medic(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range, units_t power) :
            Character(type, team,health,ammo,attack_range,power,MEDIC_MOVE_RANGE,MEDIC_RELOAD)
    {}

    Character *Medic::clone() const {
        return new Medic(*this);
    }

    bool Medic::canAttackThere(const GridPoint &source, const GridPoint &dest) const {
        return  GridPoint::distance(source,dest) <= kAttackRange;
    }

    AttackResult Medic::attackVictim(std::shared_ptr<Character> victim) {
        // attacking an empty cell or Medic attacking himself.
        if (victim == nullptr) {
            throw IllegalTarget();
        }
        if(isFriend(victim)) {  // give Medicine!
            victim->acceptMedicine(getPower());
            ammo++; // the Game will decrement that ammo.
            return STILL_ALIVE;
        }
        // victim is an enemy - Attack!
        if(isOutOfAmmo()) {
            throw OutOfAmmo();
        }
        AttackResult result = victim->getHit(getPower());
        return result;
    }

    bool Medic::checkValidVictimPos(const GridPoint &attacker, const GridPoint &victim) {
        return !(attacker == victim);
    }
}