#include "Sniper.h"
#define SPECIAL_ATTACK_MOD 3
#define SPECIAL_ATTACK_FACTOR 2
#define MIN_RANGE_FACTOR 2
namespace mtm {


    Sniper::Sniper(units_t health, units_t ammo, units_t attack_range, units_t power) {
            // Dont Forget to set counter to 0.
    }

    Character *Sniper::clone() const {
        return new Sniper(*this);
    }

    bool Sniper::canAttackThere(const GridPoint &source, const GridPoint &dest) const {
        units_t min_range = kAttackRange / MIN_RANGE_FACTOR;
        // distance to target must be at least min_range
        // distance to target must be at most kAttackRange.
        return GridPoint::distance(source,dest) >= min_range and GridPoint::distance(source,dest) <= kAttackRange;
    }

    units_t Sniper::getPower() const {
        attack_counter == 0 ? kPower*SPECIAL_ATTACK_FACTOR : kPower;
    }

    void Sniper::attackSuccess() {
        attack_counter = ++attack_counter%SPECIAL_ATTACK_MOD;
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
}