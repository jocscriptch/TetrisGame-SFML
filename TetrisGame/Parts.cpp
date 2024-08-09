#include "Parts.h"

Parts::Parts() {
    parts = {
        {
            {1, 1},
            {1, 1}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        }
    };
}

vector<array<bool, 5>> Parts::consultPart(int id) const
{
    return parts[id];
}

void Parts::rotatePart(int id)
{
    auto& part = parts[id];
    auto temp = part;
    int size = static_cast<int>(part.size());

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            part[i][j] = temp[size - j - 1][i];
        }
    }
}

void Parts::unRotatePart(int id)
{
    auto& part = parts[id];
    auto temp = part;
    int size = static_cast<int>(part.size());

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            part[i][j] = temp[j][size - i - 1];
        }
    }
}