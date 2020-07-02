#ifndef EX3_SOLDIER_H
#define EX3_SOLDIER_H
#include "Character.h"

namespace mtm {
    class Soldier : public Character {


    public:
        Soldier(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range, units_t power);
        Soldier(const Soldier&) = default;
        Soldier& operator=(const Soldier&) = delete ;

        Character* clone() const override;
        bool canAttackThere(const GridPoint &source, const GridPoint &dest) const override;
        AttackResult attackVictim(std::shared_ptr<Character> victim) override;
        void attackGrid(Matrix<std::shared_ptr<Character>>& game_mat,const GridPoint& dst_coordinates) override ;
    };
}

#endif //EX3_SOLDIER_H
