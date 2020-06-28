//
// Created by avira on 28/06/2020.
//

#include "Exceptions.h"

const char *mtm::IllegalArgument::what() const noexcept {
    return exception::what();
}

const char *mtm::IllegalCell::what() const noexcept {
    return exception::what();
}

const char *mtm::CellEmpty::what() const noexcept {
    return exception::what();
}

const char *mtm::MoveTooFar::what() const noexcept {
    return exception::what();
}

const char *mtm::CellOccupied::what() const noexcept {
    return exception::what();
}

const char *mtm::OutOfRange::what() const noexcept {
    return exception::what();
}

const char *mtm::OutOfAmmo::what() const noexcept {
    return exception::what();
}

const char *mtm::IllegalTarget::what() const noexcept {
    return exception::what();
}
