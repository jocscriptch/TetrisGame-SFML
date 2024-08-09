#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Parts.h"
using namespace std;
using namespace sf;

class Board : public Drawable
{
    private:
        Parts parts;
        int idNewPart = 0;
        int idColorNewPart = 0;
        int indX = 0, indY = 0;
        int timer = 0;
        int limitTimer = 30;
        int idNextPart = 0;        
        int idColorNextPart = 0; 
        Color newPartColor;
        Color nextPartColor;
        RectangleShape previewShapes[4][4];

        //Declaracion de la matriz[20x10]
        array<array<int, 10>, 20> board{};
        array<array<RectangleShape, 10>, 20> boardShapes;

        // para dibujar el tablero
        virtual void draw(RenderTarget& target, RenderStates states) const override;
     
    public:
        Board(); // Constructor
        bool installPart();             // Coloca una nueva pieza en el tablero
        bool updateBoard();             // Actualiza la posicion de las piezas en el tablero
        void updateBoardColors();       // Actualiza los colores de las piezas en el tablero
        void updateLimitTimer(int);     // Actualiza el limite de tiempo para la caida de las piezas
        void moveRight();               // Mueve la pieza actual a la derecha
        void moveLeft();                // Mueve la pieza actual a la izquierda
        void rotatePart();              // Rota la pieza actual
        int checkLine();                // Verifica si se ha completado una linea
        void drawPreview(RenderTarget& target) const; // Prevista de la pieza siguiente
        void updateNextPart();          // Actualiza la siguiente pieza
        void cleanBoard();              // Limpia el tablero
};