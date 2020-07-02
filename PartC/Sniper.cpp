#include "Sniper.h"
#define SPECIAL_ATTACK_MOD 3
#define SPECIAL_ATTACK_FACTOR 2
#define MIN_RANGE_FACTOR 2
#define SNIPER_MOVE_RANGE 4
#define SNIPER_RELOAD 2
#define INIT_ATTACK_COUNTER 0
namespace mtm {


    Sniper::Sniper(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range, units_t power) :
    Character(type, team,health,ammo,attack_range,power,SNIPER_MOVE_RANGE,SNIPER_RELOAD),
    attack_counter(INIT_ATTACK_COUNTER) {}



    Character *Sniper::clone() const {
        return new Sniper(*this);
    }

    bool Sniper::canAttackThere(const GridPoint &source, const GridPoint &dest) const {
        units_t min_range = ceil(double(kAttackRange) / double(MIN_RANGE_FACTOR));
        // distance to target must be at least min_range
        // distance to target must be at most kAttackRange.
        return (GridPoint::distance(source,dest) >= min_range) and (GridPoint::distance(source,dest) <= kAttackRange);
    }

    units_t Sniper::getPower() const {
        return attack_counter == 0 ? kPower*SPECIAL_ATTACK_FACTOR : kPower;
    }

    AttackResult Sniper::attackVictim(std::shared_ptr<Character> victim) {
        if(isOutOfAmmo()) {
            throw OutOfAmmo();
        }
        if (victim == nullptr or isFriend(victim)) {
            throw IllegalTarget();
        }
        AttackResult result = victim->getHit(getPower());
        attackSuccess();
        return result;
    }

    void Sniper::attackSuccess() {
        attack_counter = (attack_counter + 1)%SPECIAL_ATTACK_MOD;
    }
}