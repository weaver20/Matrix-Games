#include "Game.h"

namespace mtm {

    Game::Game(int height, int width) {

    }

    Game::Game(const Game &other) {

    }

    Game &Game::operator=(const Game &other) {

    }

    Game::~Game() {

    }

    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {

        if(game_mat(coordinates.row,coordinates.col) != nullptr) {
            throw CellOccupied();
        }
        else {
            game_mat(coordinates.row,coordinates.col) = character;
        }

    }

    std::shared_ptr<Character>
    Game::makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power) {

        if((team != CPP and team != PYTHON) or health <= 0 or ammo < 0 or range < 0 or power < 0) {
            throw IllegalArgument();
        }

        if(type == SOLDIER) {
            return std::shared_ptr<Character>(new Soldier(team, health, ammo, range, power));
        }
        else if(type == MEDIC) {
            return std::shared_ptr<Character>(new Medic(team, health, ammo, range, power));
        }
        else if(type == SNIPER) {
            return std::shared_ptr<Character>(new Sniper(team, health,ammo,range,power));
        }
        else {
            throw IllegalArgument();
        }
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {

    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {

    }

    void Game::reload(const GridPoint &coordinates) {

    }

    std::ostream &Game::printGameBoard(std::ostream &os, const char *begin, const char *end, unsigned int width) const {

    }

    bool Game::isOver(Team *winningTeam) const {

    }




    const char *Game::IllegalArgument::what() const noexcept {
        return exception::what();
    }

    const char *Game::IllegalCell::what() const noexcept {
        return exception::what();
    }

    const char *Game::CellEmpty::what() const noexcept {
        return exception::what();
    }

    const char *Game::MoveTooFar::what() const noexcept {
        return exception::what();
    }

    const char *Game::CellOccupied::what() const noexcept {
        return exception::what();
    }

    const char *Game::OutOfRange::what() const noexcept {
        return exception::what();
    }

    const char *Game::OutOfAmmo::what() const noexcept {
        return exception::what();
    }

    const char *Game::IllegalTarget::what() const noexcept {
        return exception::what();
    }

}