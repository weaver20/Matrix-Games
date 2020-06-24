#ifndef EX3_SNIPER_H
#define EX3_SNIPER_H
#include "Character.h"

namespace mtm {

    class Sniper : public Character {
    private:
    unsigned int attack_counter;
    public:
        Sniper(units_t health, units_t ammo, units_t attack_range, units_t power);
        ~Sniper() = default;
        Character* clone() const override;
        bool isInAttackRange(GridPoint& source, GridPoint& dest) const override;
        units_t getPower() const override;
        void attackSuccess() override ;
    };
}

#endif //EX3_SNIPER_H
