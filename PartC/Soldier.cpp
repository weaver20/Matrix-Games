#include "Soldier.h"
#define COLLATERAL_DAMAGE_RADIUS_FACTOR 3
#define COLLATERAL_DAMAGE_POWER_FACTOR 2
#define SOLDIER_MOVE_RANGE 3
#define SOLDIER_RELOAD 3

namespace mtm {


    Soldier::Soldier(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range, units_t power) :
            Character(type, team,health,ammo,attack_range,power,SOLDIER_MOVE_RANGE,SOLDIER_RELOAD)
            {}

    Character *Soldier::clone() const {
        return new Soldier(*this);
    }

    bool Soldier::canAttackThere(const GridPoint &source, const GridPoint &dest) const {
        // one of values (row/col) must be equalls at source and at dest
        // distance must be inside attack range.
        return GridPoint::distance(source,dest) <= kAttackRange;
    }

    AttackResult Soldier::attackVictim(std::shared_ptr<Character> victim) {
        // no Ammo to attack.
        if(isOutOfAmmo()) {
            throw OutOfAmmo();
        }

        // the attack is legal - but nothing to do.
        if(victim == nullptr or isFriend(victim)) {
            return STILL_ALIVE;
        }
        // victim is an Enemy! - Attacking:
        AttackResult result = victim->getHit(getPower());
        return result;
    }

    void Soldier::attackGrid(Matrix<std::shared_ptr<Character>> &game_mat, const GridPoint &dst_coordinates) {

        units_t collateral_range = ceil(double(kAttackRange) / double(COLLATERAL_DAMAGE_RADIUS_FACTOR));
        units_t collateral_power  = ceil(double(getPower()) / double(COLLATERAL_DAMAGE_POWER_FACTOR));
        for(Matrix<std::shared_ptr<Character>>::iterator it= game_mat.begin() ; it != game_mat.end() ; it++) {


            // Character is in Secondary Attack Range
            if(GridPoint::distance(dst_coordinates,it.getGridPoint()) <= collateral_range ) {
                // Character is an Enemy!
                if(*it != nullptr and !isFriend(*it)) {

                    // Attacking!
                    AttackResult res = (*it)->getHit(collateral_power);
                    // if Enemy is dead - remove corpse.
                    if (res == DEAD) {
                        *it = nullptr;
                    }
                }
            }
        }


    }

    bool Soldier::checkValidVictimPos(const GridPoint &attacker, const GridPoint &victim) {
        return attacker.row == victim.row or attacker.col == victim.col;
    }


}