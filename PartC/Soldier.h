#ifndef EX3_SOLDIER_H
#define EX3_SOLDIER_H
#include "Character.h"

namespace mtm {
    class Soldier : public Character {


    public:
        Soldier(units_t health, units_t ammo, units_t attack_range, units_t power);
        Soldier(Soldier&) = delete ;

        Character* clone() const override;
        bool isInAttackRange(GridPoint& source, GridPoint& dest) const override;

    };
}

#endif //EX3_SOLDIER_H
