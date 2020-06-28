//
// Created by avira on 28/06/2020.
//

#ifndef EX3_EXCEPTIONS_H
#define EX3_EXCEPTIONS_H
#include "Auxiliaries.h"

namespace mtm {
    class Exception : public std::exception {};
    
    class GameException : public mtm::Exception {
    };


    class IllegalArgument : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class IllegalCell : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class CellEmpty : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class MoveTooFar : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class CellOccupied : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class OutOfRange : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class OutOfAmmo : public GameException {
    public:
        const char *what() const noexcept override;
    };

    class IllegalTarget : public GameException {
    public:
        const char *what() const noexcept override;
    };

}

#endif //EX3_EXCEPTIONS_H
