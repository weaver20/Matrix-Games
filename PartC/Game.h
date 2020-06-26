#ifndef EX3_GAME_H
#define EX3_GAME_H
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "../PartB/Matrix.h"
#include <Auxiliaries.h>
#include <memory>

namespace mtm {
    class Game {
        Matrix<std::shared_ptr<Character>> game_mat;
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

        ~Game();

        void addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character);

        static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                        units_t health, units_t ammo, units_t range, units_t power);

        void move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        void attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);

        void reload(const GridPoint &coordinates);

        std::ostream &printGameBoard(std::ostream &os, const char *begin,
                                     const char *end, unsigned int width) const;

        bool isOver(Team *winningTeam = NULL) const;


        class GameException : public mtm::Exception {};


        class IllegalArgument : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class IllegalCell : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class CellEmpty : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class MoveTooFar : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class CellOccupied : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class OutOfRange : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class OutOfAmmo : public GameException {
        public:
            const char* what() const noexcept override;
        };
        class IllegalTarget : public GameException {
        public:
            const char* what() const noexcept override;
        };

    };

}

#endif //EX3_GAME_H
