#include <iostream>
#include <climits>
#include <fstream>
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "Humano.hpp"
#include "IA.hpp"
#include "Connect4.hpp"

using namespace std;

// Función principal
int main() {
    cout << " ** CONNECT 4 ** " << endl;

    int opcion;
    cout << "Select option:" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Jugar nueva partida" << endl;
    cout << "2. Cargar partida" << endl;
    cout << "-> ";
    cin >> opcion;

    if (opcion == 0) {
        cout << "Saiendo del programa." << endl;
        return 0;
    } else if (opcion == 1) {
        // Play a new game
        int modoJuego;
        cout << "Selecciona un modo de juego:" << endl;
        cout << "1. Jugador vs Jugador" << endl;
        cout << "2. Jugado vs IA Facil" << endl;
        cout << "3. Jugado vs IA Normal" << endl;
        cout << "4. Jugado vs IA Dificil" << endl;
        
        cin >> modoJuego;

        Jugador* jugador1 = new Humano('X');
        Jugador* jugador2 = nullptr;

        switch (modoJuego) {
            case 1:
                jugador2 = new Humano('O');
                break;
            case 2:
                jugador2 = new IA('O');
                break;
            case 3:
                jugador2 = new IA('O');
                break;
            case 4:
                jugador2 = new IA('O');
                break;
            default:
                cout << "Opcion invalida, saliendo." << endl;
                delete jugador1;
                return 1;
        }

        Connect4 juego(jugador1, jugador2);
        juego.jugar();
        // Guardar la partida
        cout << "Decea guardar la partida? (1: Si, 0: No): ";
        int saveOption;
        cin >> saveOption;

        if (saveOption == 1) {
            string nombreArchivo;
            cout << "Ingrese nombre del archivo donde guardar (ej. saved_game.csv): ";
            cin >> nombreArchivo;
            juego.guardarPartida(nombreArchivo);
        }

        delete jugador1;
        delete jugador2;
    } else if (opcion == 2) {
        
        string nombreArchivo;
        cout << "Ingrese el nombre del archivo para cargar partida (ej. saved_game.csv): ";
        cin >> nombreArchivo;

        Jugador* jugador1 = new Humano('X');
        Jugador* jugador2 = new IA('O'); // Se puede cambiar si se desea cargar el otro tipo de jugador

        Connect4 juego(jugador1, jugador2);
        juego.cargarPartida(nombreArchivo);
        juego.jugar();

        delete jugador1;
        delete jugador2;
    } else {
        cout << "Opcion invalida. saliendo" << endl;
        return 1;
    }

    return 0;
}



