#include "Board.h"

Board::Board()
{
    // Inicializacion de boardShapes
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            boardShapes[i][j] = RectangleShape(Vector2f(30.0f, 30.0f));
            boardShapes[i][j].setPosition(j * 30.0f, i * 30.0f);
            boardShapes[i][j].setFillColor(Color(50, 50, 50));
            boardShapes[i][j].setOutlineThickness(1.0f);
            boardShapes[i][j].setOutlineColor(Color(0, 0, 0));
        }
    }
    // Inicializacion de la prevista de la siguiente pieza
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            previewShapes[i][j] = RectangleShape(Vector2f(20.0f, 20.0f));
            previewShapes[i][j].setPosition(405.0f + j * 22.0f, 75.0f + i * 22.0f);
            previewShapes[i][j].setFillColor(Color(100, 100, 100));
            previewShapes[i][j].setOutlineThickness(1.0f);
            previewShapes[i][j].setOutlineColor(Color(0, 0, 0));
            
        }
    }
    updateNextPart();
}

bool Board::installPart()
{
    idNewPart = idNextPart;
    idColorNewPart = idColorNextPart;
    newPartColor = nextPartColor;

    updateNextPart();

    auto part = parts.consultPart(idNewPart);
    int size = static_cast<int>(part.size());

    indY = 0;
    indX = 5 - size / 2;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (part[i][j]) {
                if (board[i][j + indX] > 0) return false;
                board[i][j + indX] = -1;
            }
        }
    }
    return true;
}

bool Board::updateBoard()
{
    if (timer >= limitTimer) {
        int aux = 0;
        for (int i = 18; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == -1 && board[i + 1][j] <= 0) {
                    aux++;
                }
            }
        }

        if (aux == 4) {
            indY++;
            for (int i = 18; i >= 0; --i) {
                for (int j = 0; j < 10; ++j) {
                    if (board[i][j] == -1) {
                        board[i][j] = 0;
                        board[i + 1][j] = -1;
                    }
                }
            }
        }
        else {
            for (int i = 19; i >= 0; --i) {
                for (int j = 0; j < 10; ++j) {
                    if (board[i][j] == -1) board[i][j] = idColorNewPart;
                }
            }
            timer = 0;
            return true;
        }
        timer = 0;
    }
    timer++;
    return false;
}

void Board::updateBoardColors()
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 10; ++j) {
            switch (board[i][j]) {
            case 0: boardShapes[i][j].setFillColor(Color(50, 50, 50)); break;
            case 1: boardShapes[i][j].setFillColor(Color(10, 210, 255)); break;
            case 2: boardShapes[i][j].setFillColor(Color(41, 98, 255)); break;
            case 3: boardShapes[i][j].setFillColor(Color(149, 0, 255)); break;
            case 4: boardShapes[i][j].setFillColor(Color(255, 0, 89)); break;
            case 5: boardShapes[i][j].setFillColor(Color(255, 140, 0)); break;
            case 6: boardShapes[i][j].setFillColor(Color(180, 230, 0)); break;
            case 7: boardShapes[i][j].setFillColor(Color(15, 255, 219)); break;
            default: boardShapes[i][j].setFillColor(newPartColor); break;
            }
        }
    }
}

void Board::updateLimitTimer(int limit)
{
    limitTimer = limit;
}

void Board::moveRight()
{
    int aux = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == -1 && board[i][j + 1] <= 0) {
                aux++;
            }
        }
    }

    if (aux == 4) {
        indX++;
        for (int i = 0; i < 20; ++i) {
            for (int j = 9; j >= 0; --j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                    board[i][j + 1] = -1;
                }
            }
        }
    }
}

void Board::moveLeft()
{
    int aux = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 1; j < 10; ++j) {
            if (board[i][j] == -1 && board[i][j - 1] <= 0) {
                aux++;
            }
        }
    }

    if (aux == 4) {
        indX--;
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                    board[i][j - 1] = -1;
                }
            }
        }
    }
}

void Board::rotatePart()
{
    parts.rotatePart(idNewPart);
    auto part = parts.consultPart(idNewPart);
    int size = static_cast<int>(part.size());

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (part[i][j]) {
                if (indY + i < 0 || indY + i >= 20 || indX + j < 0 || indX + j >= 10 || board[indY + i][indX + j] > 0) {
                    parts.unRotatePart(idNewPart);
                    return;
                }
            }
        }
    }

    for (auto& row : board) {
        for (auto& cell : row) {
            if (cell == -1) cell = 0;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (part[i][j]) {
                board[i + indY][j + indX] = -1;
            }
        }
    }
}

int Board::checkLine()
{
    int lines = 0;

    for (int i = 19; i >= 0; --i) {
        int aux = 0;
        for (int j = 0; j < 10; ++j) {
            if (board[i][j] > 0) aux++;
            if (lines > 0) board[i + lines][j] = board[i][j], board[i][j] = 0;
        }
        if (aux == 10) {
            for (int j = 0; j < 10; ++j) board[i][j] = 0;
            lines++;
        }
    }
    return lines;
}

void Board::draw(RenderTarget& target, RenderStates states) const
{
    for (const auto& row : boardShapes) {
        for (const auto& shape : row) {
            target.draw(shape, states);
        }
    }
}

void Board::drawPreview(RenderTarget& target) const
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            target.draw(previewShapes[i][j]);
        }
    }
}

void Board::updateNextPart()
{
    idNextPart = rand() % 7;
    auto part = parts.consultPart(idNextPart);
    int color = 1 + rand() % 7;
    idColorNextPart = color;

    switch (color) {
    case 1: nextPartColor = Color(10, 210, 255); break;
    case 2: nextPartColor = Color(41, 98, 255); break;
    case 3: nextPartColor = Color(149, 0, 255); break;
    case 4: nextPartColor = Color(255, 0, 89); break;
    case 5: nextPartColor = Color(255, 140, 0); break;
    case 6: nextPartColor = Color(180, 230, 0); break;
    case 7: nextPartColor = Color(15, 255, 219); break;
    }

    // limpiar la prevista
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            previewShapes[i][j].setFillColor(Color(50, 50, 50));
        }
    }
    // pintar la siguiente pieza en la matriz
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i < part.size() && j < part.size() && part[i][j]) {
                previewShapes[i][j].setFillColor(nextPartColor);
            }
        }
    }
}

void Board::cleanBoard()
{
    board.fill({});
}