#ifndef EX3_GAME_H
#define EX3_GAME_H
#define DELIMETER " "
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "Exceptions.h"
#include "PartCMatrix.h"
#include "Auxiliaries.h"
#include <memory>
#include <cassert>

namespace mtm {
    class Game {
        Matrix <std::shared_ptr<Character>> game_mat;
        static Matrix<std::shared_ptr<Character>> copyGameBoard(const Game& matrix);

    public:
        /**
         * Creates a GameBoard sized height x width - a Matrix of shared_ptr of Characters.
         * initialize all GridPoints to nullptr.
         * @param height
         * @param width
         * Exceptions:
         *      std::bad_alloc - if an allocation error occurred.
         *      IllegalArgument - if height/width is not positive.
         */
        Game(int height, int width);
        /**
         * Copy C`tor
         * copies an existing gameboard and clones all existing Characters on the board.
         * @param other
         * Exceptions:
         *      std::bad_alloc - if an allocation error occurred.
         *
         */
        Game(const Game &other);

        /**
         * Assignment operator
         * copies an existing gameboard and clones all existing Characters on the board.
         * @param other
         * @return
         * Exceptions:
         *      std::bad_alloc - if an allocation error occurred.
         */
        Game &operator=(const Game &other);
        /**
         * Destructor - releases all memory allocated.
         */
        ~Game() = default;

        /**
         *
         * This function position a Character at the gameboard.
         * @param coordinates
         * @param character
         * Exceptions:
         *      IllegalCell - if coordinates are not on the gameboard / invalid.
         *      CellOccupied - if there already is a Character at this coordinates.
         */
        void addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character);

        /**
         * This static function creates a Character and returns a shared_ptr to that Character.
         * @param type - type of Character (SOLDIER, MEDIC, SNIPER)
         * @param team  - CPP or PYTHON
         * @param health - Health points to set
         * @param ammo - starting ammo
         * @param range - range of attack
         * @param power - power to set.
         * @return  a shared_ptr to that Character.
         * Exceptions:
         *      IllegalArgument - if argument given is invalid.
         */
        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);

        /**
         *
         * Move Character from src_coordinates to dst_coordinates
         * @param src_coordinates
         * @param dst_coordinates
         * Exceptions:
         *      IllegalCell - if src_coordinates or dst_coordinates are not on the gameboard / invalid.
         *      CellEmpty - if there is no Character at src_coordinates.
         *      MoveTooFar - if dst_coordinates is out of Characters's movement range.
         *      CellOccupied - if dst_coordinates is already occupied.
         */
        void move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);
        /**
         *  Character at src_coordinates attacks Character at dst_coordinates.
         * @param src_coordinates
         * @param dst_coordinates
         * Exceptions:
         *      IllegalCell - if src_coordinates or dst_coordinates are not on the gameboard / invalid.
         *      CellEmpty - if there is no Character at src_coordinates.
         *      OutOfRange - dst_coordinates is out of attack range.
         *      OutOfAmmo - Attacking Character has no ammo.
         *      IllegalTarget - Attacking Character is not allowed to attack there (according to Character rulles).
         */
        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        /**
         * Character at coordinates reloads ammo.
         * @param coordinates
         * Exceptions:
         *      IllegalCell - if src_coordinates or dst_coordinates are not on the gameboard / invalid.
         *      CellEmpty - if there is no Character at src_coordinates.
         */
        void reload(const GridPoint &coordinates);

        /**
         *  printing GameBoard status on the screen.
         * @param os
         * @param begin
         * @param end
         * @param width
         * @return
         *  Exceptions:
         *          TODO: Maybe std::bad_alloc ?????
         */
         friend std::ostream& operator<<(std::ostream &os, const Game& game);


        /**
         * Checks if the game in its current status can be terminated with a winner.
         * also Changes winningTeam to the winners name.
         * @param winningTeam
         * @return
         *      true - if all the Characters on the board are from the same Team.
         *      false - if there arent any Characters on the board or there are Characters from both teams on the board.
         */
        bool isOver(Team* winningTeam = NULL) const;



    };

}

#endif //EX3_GAME_H
