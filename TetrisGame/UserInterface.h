#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class UserInterface : public Drawable
{
    private:
        Font font;
        Text scoreTextTitle;
        Text scoreText;
        Text maxScoreTextTitle;
        Text maxScoreText;
        Text linesTextTitle;
        Text linesText;
        Text developerInfo;
        Text gameOverText;
        Text newScoreText;

        enum class GameState { Normal, NewScore, GameOver };
        GameState gameState = GameState::Normal;

        // para dibujar la interfaz de usuario
        virtual void draw(RenderTarget& target, RenderStates states) const override;

        // metodo para formatear y establecer el texto
        void formatText(Text& text, const Font& font, const Color& color, const Vector2f& position, unsigned int size, const string& str);

    public:
        UserInterface();  // Constructor
        void setScore(int score);      // Actualiza el puntaje en la interfaz
        void setMaxScore(int max);     // Actualiza el puntaje maximo en la interfaz
        void setLines(int lines);      // Actualiza el contador de lineas en la interfaz
        void triggerGameOver();        // Activa el estado de Game Over
        void triggerNewScore();        // Activa el estado de Nuevo Record
};