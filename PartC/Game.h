#ifndef EX3_GAME_H
#define EX3_GAME_H
#include "Soldier.h"
#include "Medic.h"
#include "Sniper.h"
#include "../PartB/Matrix.h"
#include <memory>
namespace mtm {
    class Game {

    public:
        Game(int height, int width);

        Game(const Game &other);

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


        class Exception : public mtm::Exception {
        };
        class IllegalArgument : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class IllegalCell : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class CellEmpty : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class MoveTooFar : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class CellOccupied : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class OutOfRange : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class OutOfAmmo : public Exception {
        public:
            const char* what() const noexcept override;
        };
        class IllegalTarget : public Exception {
        public:
            const char* what() const noexcept override;
        };

    };

}

#endif //EX3_GAME_H
