#include "Game.h"

namespace mtm {

    Game::Game(int height, int width): game_mat(Matrix<std::shared_ptr<Character>>(Dimensions(height, width))) {}

    Game::Game(const Game &other): game_mat(copyGameBoard(other)) {}

    Game &Game::operator=(const Game &other) {
        if(this == &other){
            return *this;
        }
        Matrix<std::shared_ptr<Character>> src_mat = other.game_mat;
        Matrix<std::shared_ptr<Character>>::iterator it2 = src_mat.begin();
        Matrix<std::shared_ptr<Character>> target_mat(Dimensions(src_mat.height(), src_mat.width()));



    }

    Game::~Game() {

    }

     Matrix<std::shared_ptr<Character>> Game::copyGameBoard(Game matrix){
         Matrix<std::shared_ptr<Character>>& src_mat = matrix.game_mat;
         Matrix<std::shared_ptr<Character>>::iterator it2 = src_mat.begin();
         Matrix<std::shared_ptr<Character>> target_mat(Dimensions(src_mat.height(), src_mat.width()));
         for(Matrix<std::shared_ptr<Character>>::iterator it1 = src_mat.begin(); it1 != src_mat.end(); it1++){
             *it2 = std::shared_ptr<Character>((*it1)->clone());
             it2++;
         }
         return target_mat;
    }



    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {

        if(game_mat(coordinates) != nullptr) {
            throw CellOccupied();
        }
        else {
            game_mat(coordinates) = character;
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
        // IlegalCell() may be thrown from operator() of PartCMatrix.
        std::shared_ptr<Character> attacker = game_mat(src_coordinates);
        std::shared_ptr<Character> victim =game_mat(dst_coordinates);
        // no Character at src_coordinates
        if (attacker == nullptr) {
            throw CellEmpty();
        }
        if(!attacker->canAttackThere(src_coordinates, dst_coordinates)) {
            throw OutOfRange();
        }

        AttackResult attack_res = attacker->attackVictim(game_mat(dst_coordinates));
        // if nothing thrown - the attack was a success.
        attacker->useAmmo();
        if(attack_res == DEAD) {
            victim = nullptr;
        }

        attacker->attackGrid(game_mat,dst_coordinates);
    }

    void Game::reload(const GridPoint &coordinates) {
        // this line may throw IllegalCell().
        std::shared_ptr<Character> character = game_mat(coordinates);
        if(character == nullptr) {
            throw CellEmpty();
        }
        character->reload();
    }

    std::ostream &Game::printGameBoard(std::ostream &os, const char *begin, const char *end, unsigned int width) const {

    }

    bool Game::isOver(Team *winningTeam) const {
        if(!any(game_mat)) {
            return false;
        }

        bool still_alive_cpp = false;
        bool still_alive_python = false;
        for(Matrix<std::shared_ptr<Character>>::const_iterator c_it = game_mat.begin() ; c_it != game_mat.end() ; c_it++) {
            if((*c_it)->getTeam() == CPP) {

            }
        }

    }





}