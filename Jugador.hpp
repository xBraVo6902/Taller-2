

#include <iostream>
#include "Tablero.hpp"
#pragma once


class Jugador {
protected:
    char figura;

public:
    Jugador(char f) : figura(f) {}

    char getFigura() const {
        return figura;
    }

    virtual void realizarMovimiento(Tablero& tablero) const = 0;
};