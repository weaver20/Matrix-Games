#ifndef EX3_MEDIC_H
#define EX3_MEDIC_H
#include "Character.h"
namespace mtm {
    class Medic : public Character {

    public:
        Medic(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range, units_t power);
        Medic(const Medic&) = default;
        Medic& operator=(const Medic&) = delete ;
        ~Medic() = default;
        Character* clone() const override;
        bool canAttackThere(const GridPoint &source, const GridPoint &dest) const override;
        AttackResult attackVictim(std::shared_ptr<Character> victim) override;
    };
}

#endif //EX3_MEDIC_H
