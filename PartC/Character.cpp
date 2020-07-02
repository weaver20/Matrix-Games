#include "Character.h"
#include <cassert>
namespace mtm {

    mtm::Character::Character(CharacterType type, Team team, units_t health, units_t ammo, units_t attack_range,
                              units_t power, units_t move_range,
                              units_t reload_amount) :
            type(type), kTeam(team), health(health), ammo(ammo), kAttackRange(attack_range), kPower(power),
            kMovementRange(move_range), kReloadAmount(reload_amount) {}

     void mtm::Character::reload() {
        ammo += kReloadAmount;
    }

    mtm::CharacterType mtm::Character::getType() const {
        return type;
    }

    // TODO: what About this?
    void mtm::Character::useAmmo() {
        assert(ammo > 0);
        ammo--;
    }

    void mtm::Character::acceptMedicine(mtm::units_t med) {
        assert(med >= 0);
        health += med;
    }

    mtm::AttackResult mtm::Character::getHit(mtm::units_t hit) {
        assert(hit >= 0);
        health -= hit;
        if (health <= 0) {
            health = 0;
            return DEAD;
        }
        return STILL_ALIVE;
    }

     bool mtm::Character::isOutOfAmmo() const {
        return ammo == 0;
    }

     bool mtm::Character::isDead() const {
        return health == 0;
    }

     mtm::units_t mtm::Character::getPower() const {
        return kPower;
    }

     mtm::units_t mtm::Character::getMoveRange() const {
        return kMovementRange;
    }

    bool mtm::Character::isFriend(std::shared_ptr<Character> &other) {
        assert(other != nullptr);
        return kTeam == other->kTeam;
    }

    void
    mtm::Character::attackGrid(mtm::Matrix<std::shared_ptr<Character>> &game_mat,
                               const mtm::GridPoint &dst_coordinates) {}

    mtm::Team mtm::Character::getTeam() const {
        return kTeam;
    }

    bool Character::checkValidVictimPos(const GridPoint &attacker, const GridPoint &victim) {
        return true;
    }
}