
#include <iostream>
#pragma once
using namespace std;


const int FILAS = 6;
const int COLUMNAS = 7;

class Tablero {
private:
    char tablero[FILAS][COLUMNAS];

public:
    Tablero() {
        reiniciarTablero();
    }

    void reiniciarTablero() {
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                tablero[i][j] = ' ';
            }
        }
    }

    void verTablero() const {
        cout << " 1 2 3 4 5 6 7 " << endl;
        for (int i = 0; i < FILAS; ++i) {
            cout << "|";
            for (int j = 0; j < COLUMNAS; j++) {
                cout << tablero[i][j] << "|";
            }
            cout << endl;
        }
        cout << "___________________" << endl;
    }

    bool dropFicha(int col, char figura) {
        for (int i = FILAS - 1; i >= 0; --i) {
            if (tablero[i][col] == ' ') {
                tablero[i][col] = figura;
                return true; // Se pudo colocar la ficha en la columna
            }
        }
        return false; // La columna está llena y no se pudo colocar la ficha
    }

    char getPosicion(int fila, int columna) const {
        return tablero[fila][columna];
    }

    bool isValidMove(int col) const {
        return col >= 0 && col < COLUMNAS && tablero[0][col] == ' ';
    }

    bool tableroFull() const {
        for (int i = 0; i < COLUMNAS; ++i) {
            if (isValidMove(i)) {
                return false;
            }
        }
        return true;
    }

    bool checkWin(char figura) const {
        // Evaluar horizontalmente
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j <= COLUMNAS - 4; ++j) {
                int count = 0;
                for (int k = 0; k < 4; ++k) {
                    if (tablero[i][j + k] == figura) {
                        count++;
                    }
                }
                if (count == 4) {
                    return true;
                }
            }
        }

        // Evaluar verticalmente
        for (int j = 0; j < COLUMNAS; ++j) {
            for (int i = 0; i <= FILAS - 4; ++i) {
                int count = 0;
                for (int k = 0; k < 4; ++k) {
                    if (tablero[i + k][j] == figura) {
                        count++;
                    }
                }
                if (count == 4) {
                    return true;
                }
            }
        }

        // Evaluar diagonales
        for (int i = 0; i <= FILAS - 4; ++i) {
            for (int j = 0; j <= COLUMNAS - 4; ++j) {
                int count = 0;
                for (int k = 0; k < 4; ++k) {
                    if (tablero[i + k][j + k] == figura) {
                        count++;
                    }
                }
                if (count == 4) {
                    return true;
                }
            }
        }

        return false;
    }
};