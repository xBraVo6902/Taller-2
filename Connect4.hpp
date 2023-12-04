
#pragma once
#include <iostream>
#include <fstream>
#include "Tablero.hpp"
#include "Jugador.hpp"



class Connect4 { // Clase principal del juego
private:
    Tablero tablero;
    Jugador* jugador1;
    Jugador* jugador2;
    bool turnoJugador1 = true;

public:
    Connect4(Jugador* j1, Jugador* j2) : jugador1(j1), jugador2(j2) {}// Constructor

    void jugar() { // Función para jugar una partida
        bool gameOver = false;
        bool turnoJugador1 = true;
    
        while (!gameOver) {
            if (turnoJugador1) {
                jugador1->realizarMovimiento(tablero);
                if (tablero.checkWin(jugador1->getFigura())) {
                    cout << "Jugador " << jugador1->getFigura() << " Gana!" << endl;
                    gameOver = true;
                }
            } else {
                jugador2->realizarMovimiento(tablero);
                if (tablero.checkWin(jugador2->getFigura())) {
                    cout << "Jugador " << jugador2->getFigura() << " Gana!" << endl;
                    gameOver = true;
                }
            }

            if (tablero.tableroFull()) {
                cout << "It's a draw!" << endl;
                gameOver = true;
            }

            turnoJugador1 = !turnoJugador1;
        }
    }

    // Función para guardar la partida en un archivo CSV
    void guardarPartida(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            // Guardar el estado del tablero
            for (int i = 0; i < FILAS; ++i) {
                for (int j = 0; j < COLUMNAS; ++j) {
                    archivo << tablero.getPosicion(i, j);
                    if (j < COLUMNAS - 1) {
                        archivo << ",";
                    }
                }
                archivo << endl;
            }

            // Guardar el turno del jugador actual
            archivo << (turnoJugador1 ? 'X' : 'O') << endl;

            archivo.close();
            cout << "Partida guardada en " << nombreArchivo << endl;
        } else {
            cout << "No se puede abrir el archivo para guardarlo." << endl;
        }
    }

    // Función para cargar una partida desde un archivo CSV
    void cargarPartida(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            // Cargar el estado del tablero
            for (int i = 0; i < FILAS; ++i) {
                for (int j = 0; j < COLUMNAS; ++j) {
                    char c;
                    archivo >> c;
                    tablero.dropFicha(j, c);
                    archivo.ignore(); // Ignorar la coma
                }
            }

            // Cargar el turno del jugador actual
            char turno;
            archivo >> turno;
            turnoJugador1 = (turno == 'X');

            archivo.close();
            cout << "Partida cargada desde " << nombreArchivo << endl;
        } else {
            cout << "No se puede abrir el archivo para cargarlo." << endl;
        }
    }
    


};