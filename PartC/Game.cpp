#include "Game.h"

namespace mtm {

    Game::Game(int height, int width) {

    }

    Game::Game(const Game &other) {

    }

    Game &Game::operator=(const Game &other) {
        return <#initializer#>;
    }

    Game::~Game() {

    }

    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {

    }

    std::shared_ptr<Character>
    Game::makeCharacter(CharacterType type, Team team, units_t health, units_t ammo, units_t range, units_t power) {
        return std::shared_ptr<Character>();
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {

    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {

    }

    void Game::reload(const GridPoint &coordinates) {

    }

    std::ostream &Game::printGameBoard(std::ostream &os, const char *begin, const char *end, unsigned int width) const {
        return <#initializer#>;
    }

    bool Game::isOver(Team *winningTeam) const {
        return false;
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