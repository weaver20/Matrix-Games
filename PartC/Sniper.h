#ifndef EX3_SNIPER_H
#define EX3_SNIPER_H
#include "Character.h"

namespace mtm {

    class Sniper : public Character {
    private:
    unsigned int attack_counter;
    public:
        Sniper(Team team, units_t health, units_t ammo, units_t attack_range, units_t power);
        Sniper(const Sniper&) = default;
        Sniper& operator=(const Sniper&) = delete ;
        ~Sniper() = default;
        Character* clone() const override;
        bool canAttackThere(const GridPoint &source, const GridPoint &dest) const override;
        units_t getPower() const override;
        void attackSuccess();
        AttackResult attackVictim(std::shared_ptr<Character> victim) override;
    };
}

#endif //EX3_SNIPER_H
