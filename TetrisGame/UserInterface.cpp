#include "UserInterface.h"

UserInterface::UserInterface()
{
    if (!font.loadFromFile("Luckiest.ttf")) {
        cerr << "Error al cargar la fuente" << endl;
    }

    formatText(scoreTextTitle, font, Color::Yellow, { 365, 200 }, 30, "Puntuación");
    formatText(maxScoreTextTitle, font, Color::Magenta, { 402, 310 }, 30, "Récord");
    formatText(scoreText, font, Color::White, { 418, 250 }, 25, "0000");
    formatText(maxScoreText, font, Color::White, { 420, 360 }, 25, "0000");
    formatText(linesTextTitle, font, Color(0, 127, 255), {402, 410}, 30, "Líneas");
    formatText(linesText, font, Color::White, { 420, 460 }, 25, "0000");
    formatText(developerInfo, font, Color::Cyan, { 394, 555 }, 15, "\t\t\t\tBy\n\tjocscriptch");
    formatText(gameOverText, font, Color::Red, { 380, 30 }, 30, "¡Game Over!");
    formatText(newScoreText, font, Color::Green, { 320, 20 }, 35, "¡Nuevo Récord!");

    gameOverText.setCharacterSize(25);
}

void UserInterface::formatText(Text& text, const Font& font, const Color& color, const Vector2f& position, unsigned int size, const string& str)
{
    text.setFont(font);
    text.setFillColor(color);
    text.setPosition(position);
    text.setCharacterSize(size);
    text.setString(str);
}

void UserInterface::setScore(int score)
{
    scoreText.setString((score <= 9 ? "000" : score <= 99 ? "00" : score <= 999 ? "0" : "") + to_string(score));
}

void UserInterface::setMaxScore(int max)
{
    maxScoreText.setString((max <= 9 ? "000" : max <= 99 ? "00" : max <= 999 ? "0" : "") + to_string(max));
}

void UserInterface::setLines(int lines) {
    linesText.setString((lines <= 9 ? "000" : lines <= 99 ? "00" : lines <= 999 ? "0" : "") + to_string(lines));
}

void UserInterface::triggerGameOver()
{
    gameState = GameState::GameOver;
}

void UserInterface::triggerNewScore()
{
    gameState = GameState::NewScore;
}

void UserInterface::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(scoreTextTitle, states);
    target.draw(scoreText, states);
    target.draw(maxScoreTextTitle, states);
    target.draw(maxScoreText, states);
    target.draw(linesTextTitle, states);
    target.draw(linesText, states);
    target.draw(developerInfo, states);

    switch (gameState) {
    case GameState::GameOver:
        target.draw(gameOverText, states);
        break;
    case GameState::NewScore:
        target.draw(newScoreText, states);
        break;
    default:
        break;
    }
}