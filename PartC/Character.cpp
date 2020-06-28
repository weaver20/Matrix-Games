#include "Character.h"

mtm::Character::Character(units_t health, units_t ammo, units_t, units_t attack_range, units_t power,
                          units_t move_range,
                          units_t reload_amount, Team team) {

}

void mtm::Character::reload() {

}

void mtm::Character::attackSuccess() {

}

void mtm::Character::acceptMedicine(mtm::units_t med) {

}

void mtm::Character::getHit(mtm::units_t hit) {

}

bool mtm::Character::outOfAmmo() const {
    return false;
}

bool mtm::Character::isDead() const {
    return false;
}

mtm::units_t mtm::Character::getPower() const {
    return 0;
}

mtm::units_t mtm::Character::getMoveRange() const {
    return 0;
}
