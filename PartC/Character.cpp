#include "Character.h"

mtm::Character::Character(mtm::units_t health, mtm::units_t ammo, mtm::units_t, mtm::units_t attack_range,
                          mtm::units_t power, mtm::units_t move_range, mtm::units_t reload_ammount) {

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
