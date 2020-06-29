#ifndef EX3_MEDIC_H
#define EX3_MEDIC_H
#include "Character.h"
namespace mtm {
    class Medic : public Character {

    public:
        Medic(Team team, units_t health, units_t ammo, units_t attack_range, units_t power);
        ~Medic() = default;
        Character* clone() const override;
        bool isInAttackRange(GridPoint& source, GridPoint& dest) const override;

    };
}

#endif //EX3_MEDIC_H
