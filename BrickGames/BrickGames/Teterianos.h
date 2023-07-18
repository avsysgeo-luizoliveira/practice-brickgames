#pragma once
#include "Utils.h"

struct Tretros
{
    char tetrominions[16]{};
    int x = 0, y = 0;
    bool stop = false;
    bool screen = false;
    void Draw(int CX, int CY) 
    {
        int PX = CX - x;
        int PY = CY - y;
        if (PX > 3)
            return;
        if (PY > 3)
            return;

        if (PX < 0)
            return;
        if (PY < 0)
            return;

        int indexDraw = (PY * 4) + PX;

        if (indexDraw >= 0)
            std::cout << tetrominions[indexDraw];
        else
            std::cout << " ";

    }


};


class Teterianos
{
private:
    uint8_t ScreenPoints[20][30]{0};
    const char tetrominos[7][16] = {
        // I
        {
            ' ', '0', ' ', ' ',
            ' ', '0', ' ', ' ',
            ' ', '0', ' ', ' ',
            ' ', '0', ' ', ' '
        },

        // J
        {
            '1', ' ', ' ',
            '1', '1', '1',
            ' ', ' ', ' '
        },

        // L
        {
            ' ', ' ', '2',
            '2', '2', '2',
            ' ', ' ', ' '
        },

        // O
        {
            ' ', '3', '3', ' ',
            ' ', '3', '3', ' ',
            ' ', ' ', ' ', ' ',
            ' ', ' ', ' ', ' '
        },

        // S
        {
            ' ', '4', '4',
            '4', '4', ' ',
            ' ', ' ', ' '
        },

        // T
        {
            ' ', '5', ' ',
            '5', '5', '5',
            ' ', ' ', ' '
        },

        // Z
        {
            '6', '6', ' ',
            ' ', '6', '6',
            ' ', ' ', ' '
        }
    };
   
    std::vector<Tretros> listTetrominos;
    HANDLE hC;

public:
    void show();
    Teterianos(HANDLE hConsole)
    {
        hC = hConsole;
        show();
    }
protected:
        Tretros Generation();


};

