#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "UserInterface.h"
#include "Sounds.h"
#include <fstream>
using namespace std;
using namespace sf;

// para manejar la entrada del usuario
void handleInput(Board& board, int& right, int& left, int& up)
{
    if (Keyboard::isKeyPressed(Keyboard::Up) && !up) {
        board.rotatePart();
        up = 1;
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Up)) {
        up = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        board.updateLimitTimer(5);
    }
    else {
        board.updateLimitTimer(25);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right) && !right) {
        board.moveRight();
        right = 1;
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Right)) {
        right = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right) && right) {
        right++;
        if (right == 6) right = 0;
    }

    if (Keyboard::isKeyPressed(Keyboard::Left) && !left) {
        board.moveLeft();
        left = 1;
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Left)) {
        left = 0;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left) && left) {
        left++;
        if (left == 6) left = 0;
    }
}

// para actualizar el estado del juego
bool updateGame(Board& board, Sounds& sounds, UserInterface& ui, int& score, int& maxScore, int& lines)
{
    if (board.updateBoard()) {
        if (!board.installPart()) {
            sounds.pauseMusic();
            if (score > maxScore) {
                ui.triggerNewScore();
                ofstream out("maxScore.txt");
                out << score;
                sounds.playNewScore();
            }
            else {
                ui.triggerGameOver();
                sounds.playGameOver();
            }
            return false;
        }
    }
    board.updateBoardColors();

    int completedLines = board.checkLine();
    if (completedLines > 0) {
        lines += completedLines;
        ui.setLines(lines);
        sounds.playLine();
    }

    int newScore = completedLines * 5;
    score += newScore;
    ui.setScore(score);

    return true;
}

int main()
{
    Board board;
    UserInterface ui;
    Sounds sounds;

    RenderWindow window(VideoMode(600, 600), "Tetris");
    window.setFramerateLimit(60);

    board.installPart();

    int right = 0, left = 0, up = 0;
    int score = 0;
    int maxScore = 0;
    int lines = 0;
    bool isGameRunning = true;

    // leer el record desde el archivo
    fstream in("maxScore.txt");
    in >> maxScore;
    ui.setMaxScore(maxScore);
    ui.setScore(score);
    ui.setLines(lines);

    sounds.playMusic();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if (isGameRunning) {
            handleInput(board, right, left, up);
            isGameRunning = updateGame(board, sounds, ui, score, maxScore, lines);
        }

        window.clear(Color(20, 20, 20));
        window.draw(board);
        window.draw(ui);
        board.drawPreview(window);
        window.display();
    }
    return 0;
}