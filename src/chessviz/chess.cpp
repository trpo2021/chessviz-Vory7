
#include <iostream>
#include <math.h>
#include "bibl.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int countar[8], countar1[8];
    for(int i = 0; i < 8; ++i) countar[i] = 0;
    char Board[11][11];
    CellBOARD(Board);
    char FiguresP[5];
    while(true){
        std::cout << "Введите координату клетки нужной фигуры и координату клетки 'назначения'(пример: E2-E5): " << std::endl;
        for(int i = 0; i < 5; ++i)
            std::cin >> FiguresP[i];
        Move(Board, FiguresP, countar, countar1);
    }
    return 0;
}
