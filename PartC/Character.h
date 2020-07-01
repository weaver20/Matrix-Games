#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H
#include "Auxiliaries.h"
#include "PartCMatrix.h"
#include "Exceptions.h"
#include <memory>

namespace mtm {

    enum AttackResult  {DEAD, STILL_ALLIVE};

    class Character {

    protected:
        const Team kTeam;
        units_t health;
        units_t ammo;
        const units_t kAttackRange;
        const units_t kPower;
        const units_t kMovementRange;
        const units_t kReloadAmount;

    public:
        Character(Team team, units_t health, units_t ammo, units_t attack_range, units_t power, units_t move_range,
                  units_t reload_amount);

        Character(const Character&) = default;
        Character& operator=(const Character&) = delete ; // Can't change const values after init.
        ~Character() = default;

        /**
         * checks if another character is in my team or not
         * @param other
         * @return true - if other is in my team
         *          false - otherwise.
         */
        bool isFriend(std::shared_ptr<Character>& other);

        /**
         * this abstract function implemented by inheriting classes clones the Object.
         * @return pointer to cloned Object
         *
         */
        virtual Character* clone() const = 0;
        /**
         * reloads ammo with reload_amount
         */
        void reload();
        /**
         * decrement ammo in case of a Successful attack.
         */
         void useAmmo();
        /**
         * adds med to health in case of Medic Healing
         * @param med
         */
        void acceptMedicine(units_t med);
        /**
         * removes hit from health in case of an attack
         * @param hit
         */
        AttackResult getHit(units_t hit);

        /**
         * Character has no more ammo
         * @return
         *      true - if ammo = 0.
         *      false - if ammo > 0.
         */
        bool isOutOfAmmo() const; // maybe just an exception thrown by attackSuccess))
        /**
         * Character health is 0
         * @return
         *      true - if health = 0.
         *      false - if health > 0.
         */
        bool isDead() const;

        /**
         *  gives the power of the current attack (is different only at Sniper).
         * @return
         *      units_t power
         */
        virtual units_t getPower() const;
        /**
         * getter for movement_range
         * @return
         *          units_t movement_range
         */
        units_t getMoveRange() const;
        /**
         * checks if a Character can attack from source to dest
         * @param source - source GridPoint
         * @param dest - destination GridPoint
         * @return  true - if an attack is in range
         *          false - otherwise.
         */
         virtual bool canAttackThere(const GridPoint &source, const GridPoint &dest) const = 0;
        /**
         * This function attacks another character according to attacker Character rules.
         * @param victim - the Character to attack
         * @return  DIED - if victim's HP <= 0 after the attack
         *          STILL_ALIVE - otherwise.
         */
        virtual AttackResult attackVictim(std::shared_ptr<Character> victim) = 0;

        /**
         * This function is responsible for collateral damage cause by an attack (by Soldier)
         * if not overridden this function does nothing!
         * @param game_mat
         * @param dst_coordinates
         */
        virtual void attackGrid(Matrix<std::shared_ptr<Character>>& game_mat,const GridPoint& dst_coordinates);

        /**
         * returns the team of the Character.
         * @return
         */
        Team getTeam() const;
    };

}

#endif //EX3_CHARACTER_H
