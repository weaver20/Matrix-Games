#ifndef EX3_SNIPER_H
#define EX3_SNIPER_H
#include "Character.h"

namespace mtm {

    class Sniper : public Character {
    private:
        // This will keep track about when Sniper's Special attack occurs.
    unsigned int attack_counter;
    public:
        Sniper(Team team, units_t health, units_t ammo, units_t attack_range, units_t power);
        Sniper(const Sniper&) = default;
        Sniper& operator=(const Sniper&) = delete ;
        ~Sniper() = default;
        Character* clone() const override;
        bool canAttackThere(const GridPoint &source, const GridPoint &dest) const override;
        units_t getPower() const override;
        AttackResult attackVictim(std::shared_ptr<Character> victim) override;
        /**
         * In case of a successful attack this function will make sure the attack_counter is changed accordingly.
         */
        void attackSuccess();
    };
}

#endif //EX3_SNIPER_H
