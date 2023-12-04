
#pragma once
#include <iostream>
#include "Tablero.hpp"
#include "Jugador.hpp"



// IA que realiza movimientos aleatorios
class IA : public Jugador {
public:
    IA(char f) : Jugador(f) {}

    void realizarMovimiento(Tablero& tablero) const override {
        int bestMove = minimax(tablero, 6, getFigura(), INT_MIN, INT_MAX);

        if (bestMove != -1) {
            tablero.dropFicha(bestMove, getFigura());
            cout << "IA move: " << bestMove + 1 << endl;
            tablero.verTablero();
        }
    }

private:
    // Función minimax con poda alfa-beta
    int minimax(Tablero& tablero, int depth, char jugador, int alpha, int beta) const {
        if (depth == 0 || tablero.checkWin('X') || tablero.checkWin('O') || tablero.tableroFull()) {
            return evaluarTablero(tablero, jugador);
        }

        int bestMove = -1;
        
        for (int col = 0; col < COLUMNAS; ++col) {
            if (tablero.isValidMove(col)) {
                Tablero tempTablero = tablero;
                tempTablero.dropFicha(col, jugador);
                int eval = -minimax(tempTablero, depth - 1, jugador == 'X' ? 'O' : 'X', -beta, -alpha);

                if (eval > alpha) {
                    alpha = eval;
                    bestMove = col;
                }

                if (alpha >= beta) {
                    break;  // Poda alfa-beta
                }
            }
        }

        return bestMove;
    }

    int evaluarTablero(const Tablero& tablero, char jugador) const {
    char oponente = (jugador == 'X') ? 'O' : 'X';

    // Evaluar horizontalmente y defensa
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j <= COLUMNAS - 4; ++j) {
            int countJugador = 0;
            int countOponente = 0;
            for (int k = 0; k < 4; ++k) {
                if (tablero.getPosicion(i, j + k) == jugador) {
                    countJugador++;
                } else if (tablero.getPosicion(i, j + k) == oponente) {
                    countOponente++;
                }
            }
            if (countJugador == 4) {
                return 1;  // Jugador actual gana
            }
            if (countOponente == 4) {
                return -1;  // Oponente gana
            }
            if (countJugador == 3 && countOponente == 0) {
                return -10;  // Defensa: Evitar que el jugador forme una línea de 4
            }
            if (countOponente == 3 && countJugador == 0) {
                return -100;  // Bloquear al oponente que tiene 3 en línea
            }
        }
    }

        // Evaluar verticalmente y defensa
        for (int j = 0; j < COLUMNAS; ++j) {
            for (int i = 0; i <= FILAS - 4; ++i) {
                int countJugador = 0;
                int countOponente = 0;
                for (int k = 0; k < 4; ++k) {
                    if (tablero.getPosicion(i + k, j) == jugador) {
                        countJugador++;
                    } else if (tablero.getPosicion(i + k, j) == oponente) {
                        countOponente++;
                    }
                }
                if (countJugador == 4) {
                    return 1;  // Jugador actual gana
                }
                if (countOponente == 4) {
                    return -1;  // Oponente gana
                }
                if (countJugador == 3 && countOponente == 0) {
                    return -10;  // Defensa: Evitar que el jugador forme una línea de 4
                }
            }
        }

        // Evaluar diagonales y defensa
        for (int i = 0; i <= FILAS - 4; ++i) {
            for (int j = 0; j <= COLUMNAS - 4; ++j) {
                int countJugador = 0;
                int countOponente = 0;
                for (int k = 0; k < 4; ++k) {
                    if (tablero.getPosicion(i + k, j + k) == jugador) {
                        countJugador++;
                    } else if (tablero.getPosicion(i + k, j + k) == oponente) {
                        countOponente++;
                    }
                }
                if (countJugador == 4) {
                    return 1;  // Jugador actual gana
                }
                if (countOponente == 4) {
                    return -1;  // Oponente gana
                }
                if (countJugador == 3 && countOponente == 0) {
                    return -10;  // Defensa: Evitar que el jugador forme una línea de 4
                }
            }
        }

        return 0;  // Empate
    }
};