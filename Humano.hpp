
#pragma once
#include <iostream>
#include "Tablero.hpp"
#include "Jugador.hpp"


// Jugador humano que realiza movimientos a través de la consola
class Humano : public Jugador {
public:
    Humano(char f) : Jugador(f) {}

    void realizarMovimiento(Tablero& tablero) const override {
        int col;
        bool validMove = false;

        while (!validMove) {
            cout << "Jugador " << getFigura() << ", selecciona una columna (1-7): ";
            cin >> col;
            col--; // Ajustar al índice del array

            if (tablero.isValidMove(col)) {
                tablero.dropFicha(col, getFigura());
                tablero.verTablero();
                validMove = true;
            } else {
                cout << "Movimiento invalido, intente otra vez" << endl;
            }
        }
    }
};