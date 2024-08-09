#pragma once
#include <vector>
#include <array>
using namespace std;

class Parts
{
    private:
        vector<vector<array<bool, 5>>> parts;

    public:
        Parts(); // Constructor
        vector<array<bool, 5>> consultPart(int id) const;  // Devuelve la matriz de la pieza
        void rotatePart(int id);      // Rota la pieza indicada
        void unRotatePart(int id);    // Deshace la rotacion de la pieza
};