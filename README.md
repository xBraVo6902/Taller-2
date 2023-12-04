# Taller-2
Implementación del Juego Conecta 4

Resumen
Esta implementación del juego Conecta 4 está diseñada para permitir a los jugadores enfrentarse entre sí o contra diferentes niveles de oponentes controlados por la inteligencia artificial (IA). El juego se juega en una cuadrícula de 6x7, y el objetivo es conectar cuatro discos propios en fila horizontal, vertical o diagonalmente antes que el oponente.

Detalles de la Implementación
Clases
Tablero:

Representa el tablero de juego.
Maneja el estado del juego, los movimientos de los jugadores y las condiciones de victoria o empate.
Utiliza un array 2D para representar el tablero y proporciona métodos para colocar fichas, verificar victorias y mostrar el tablero.
Jugador:

Una clase abstracta que representa a un jugador en el juego.
Tiene un atributo 'figura' (pieza de juego) y un método para realizar un movimiento, que se implementa de manera diferente para jugadores humanos e IA.
Humano:

Hereda de Jugador.
Permite que un jugador humano realice un movimiento seleccionando una columna.
IA:

Hereda de Jugador.
Implementa un sencillo algoritmo Minimax con poda alfa-beta para realizar movimientos inteligentes.
Connect4:

Gestiona el flujo del juego e interacciones entre jugadores.
Ofrece opciones para jugar un nuevo juego, guardar el estado del juego en un archivo y cargar un juego guardado.
Modos de Juego:
Humano vs Humano: Dos jugadores humanos se turnan para realizar movimientos.
Humano vs IA Fácil: Un jugador humano se enfrenta a un oponente IA con una selección básica de movimientos.
Humano vs IA Normal: Un jugador humano se enfrenta a un oponente IA con un algoritmo Minimax más avanzado.
Humano vs IA Difícil: Un jugador humano se enfrenta a un oponente IA con Minimax y poda alfa-beta.
Decisiones de Diseño
Modularidad:

Cada componente principal (Tablero, Jugador, Juego) se implementa como una clase separada, promoviendo la legibilidad y mantenimiento del código.
Uso de principios de programación orientada a objetos para abstracción y encapsulamiento.
Abstracción de Jugadores:

La clase 'Jugador' sirve como abstracción para jugadores humanos e IA, permitiendo una fácil extensión a otros tipos de jugadores.
Complejidad de la IA:

Se implementan tres niveles de complejidad de IA, con la IA más desafiante utilizando Minimax con poda alfa-beta para una selección eficiente de movimientos.
Pruebas y Resultados
Rendimiento de Minimax:
Las pruebas comparativas entre Minimax con y sin poda alfa-beta mostraron una mejora significativa en la capacidad de la IA para realizar movimientos más inteligentes con la poda habilitada.
La implementación con poda alfa-beta exhibió una toma de decisiones más rápida y un juego más efectivo contra oponentes desafiantes.
Cómo Jugar:
Ejecute el programa y seleccione el modo de juego deseado.
Si juega contra la IA, elija el nivel de dificultad de la IA.
Realice movimientos ingresando el número de columna cuando se le solicite.
El juego termina cuando un jugador gana o el tablero está lleno (empate).
Opcionalmente, guarde o cargue juegos durante la sesión.
Guardar y Cargar Juegos:
Cuando se le solicite, los jugadores pueden optar por guardar el estado del juego en un archivo CSV o cargar un juego guardado anteriormente.
