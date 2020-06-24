#ifndef EX3_CHARACTER_H
#define EX3_CHARACTER_H
#include "Auxiliaries.h"
namespace mtm {
    class Character {

    protected:
        units_t health;
        units_t ammo;
        const units_t kAttackRange;
        const units_t kMovementRange;
        const units_t kPower;
        const units_t kReloadAmmount;

    public:
        Character(units_t health, units_t ammo, units_t ,units_t attack_range, units_t power,
                  units_t move_range, units_t reload_ammount);

        Character(Character&) = default;            // TODO is it?
        Character& operator=(Character&) = delete ; // TODO is it?
        ~Character() = default;

        /**
         * this abstract function implemented by inheriting classes clones the Object.
         * @return pointer to cloned Object
         *
         */
        virtual Character* clone() const = 0;
        /**
         * reloads ammo with reload_ammount
         */
        void reload();
        /**
         * decrement ammo in case of a Successful attack.
         */
        virtual void attackSuccess();
        /**
         * adds med to health in case of Medic Healing
         * @param med
         */
        void acceptMedicine(units_t med);
        /**
         * removes hit from health in case of an attack
         * @param hit
         */
        void getHit(units_t hit);

        /**
         * Character has no more ammo
         * @return
         *      true - if ammo = 0.
         *      false - if ammo > 0.
         */
        bool outOfAmmo() const; // maybe just an exception thrown by attackSuccess))
        /**
         * Character health is 0
         * @return
         *      true - if health = 0.
         *      false - if health > 0.
         */
        bool isDead() const;

        /**
         *  gives the power of the attack
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
        virtual bool isInAttackRange(GridPoint& source, GridPoint& dest) const = 0;



    };
}

#endif //EX3_CHARACTER_H
