#include "Game.h"

namespace mtm {

    Game::Game(int height, int width): game_mat(Matrix<std::shared_ptr<Character>>(Dimensions(height, width))) {}

    Game::Game(const Game &other): game_mat(copyGameBoard(other)) {}

    Game& Game::operator=(const Game &other) {
        if(this == &other){
            return *this;
        }
        Matrix<std::shared_ptr<Character>> temp_mat = copyGameBoard(other);
        game_mat = temp_mat;
        return *this;
    }


    // Static method
     Matrix<std::shared_ptr<Character>> Game::copyGameBoard(const Game& matrix){
         Matrix<std::shared_ptr<Character>>::const_iterator it2 = matrix.game_mat.begin();
         Matrix<std::shared_ptr<Character>> target_mat(Dimensions(matrix.game_mat.height(), matrix.game_mat.width()));
         for(Matrix<std::shared_ptr<Character>>::iterator it1 = target_mat.begin(); it1 != target_mat.end(); it1++, it2++) {
             if (*it2 != nullptr) {
                 *it1 = std::shared_ptr<Character>((*it2)->clone());
             }
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
            return std::shared_ptr<Character>(new Soldier(type, team, health, ammo, range, power));
        }
        else if(type == MEDIC) {
            return std::shared_ptr<Character>(new Medic(type, team, health, ammo, range, power));
        }
        else if(type == SNIPER) {
            return std::shared_ptr<Character>(new Sniper(type, team, health,ammo,range,power));
        }
        else {
            throw IllegalArgument();
        }
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) {
        std::shared_ptr<Character> src_ptr = game_mat(src_coordinates);
        std::shared_ptr<Character> dst_ptr = game_mat(dst_coordinates);
        if(src_ptr == nullptr){
            throw CellEmpty();
        }
        if(src_ptr->getMoveRange() < GridPoint::distance(src_coordinates, dst_coordinates)){
            throw MoveTooFar();
        }
        if(src_ptr == dst_ptr){
            throw GameException();
        }
        if(dst_ptr != nullptr){
            throw CellOccupied();
        }
        game_mat(dst_coordinates) = src_ptr;
        game_mat(src_coordinates) = nullptr;
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
            game_mat(dst_coordinates) = nullptr;
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

    std::ostream& operator<<(std::ostream& os, const Game& game) {
        std::string str_ptr;
        for(Matrix<std::shared_ptr<Character>>::const_iterator it = game.game_mat.begin(); it != game.game_mat.end(); it++){
            std::shared_ptr<Character> character = *it;
            if(character == nullptr){
                str_ptr += DELIMETER;
            }
            else if(character->clone()->getType() == MEDIC){
                str_ptr += character->getTeam() == CPP ? "M" : "m";
            }
            else if(character->clone()->getType() == SOLDIER){
                str_ptr += character->getTeam() == CPP ? "M" : "m";
            }
            else if(character->clone()->getType() == SNIPER){
                str_ptr += character->getTeam() == CPP ? "M" : "m";
            }
        }
        return printGameBoard(os, &str_ptr[0], &str_ptr[0] + str_ptr.length(), game.game_mat.width());


    }

    bool Game::isOver(Team* winningTeam) const {

        bool still_alive_cpp = false;
        bool still_alive_python = false;

        for(Matrix<std::shared_ptr<Character>>::const_iterator it = game_mat.begin(); it != game_mat.end(); it++) {
            std::shared_ptr<Character> character = *it;
            if(character != nullptr){
                still_alive_cpp = still_alive_cpp and character->getTeam() == CPP;
                still_alive_python = still_alive_python and character->getTeam() == PYTHON;
            }
        }

        if(still_alive_python == still_alive_cpp){
            still_alive_cpp = still_alive_python = false;
        }

        if(winningTeam){
            if(still_alive_python){
                *winningTeam = PYTHON;
            }
            if(still_alive_cpp){
                *winningTeam = CPP;
            }
        }
        return still_alive_cpp or still_alive_python;
    }





}