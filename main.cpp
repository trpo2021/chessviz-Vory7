#include <iostream>

void PrintBoard(char Board[11][11])
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << Board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Figures(char Board[11][11])
{
    for (int i = 1; i < 9; i++) {
        if (i == 1) {
            Board[i][1] = 'R'; // Black Rook
            Board[i][2] = 'H'; // Black Horse
            Board[i][3] = 'B'; // Black Bishop
            Board[i][4] = 'Q'; // Black Queen
            Board[i][5] = 'K'; // Black King
            Board[i][6] = 'B'; // Black Bishop
            Board[i][7] = 'H'; // Black Horse
            Board[i][8] = 'R'; // Black Rook
        }
        if (i == 2) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'P'; // Black pawn
            }
        }
        if (i == 7) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'p'; // White pawn
            }
        }
        if (i == 8) {
            Board[i][1] = 'r'; // White Rook
            Board[i][2] = 'h'; // White Horse
            Board[i][3] = 'b'; // White Bishop
            Board[i][4] = 'q'; // White Queen
            Board[i][5] = 'k'; // White King
            Board[i][6] = 'b'; // White Bishop
            Board[i][7] = 'h'; // White Horse
            Board[i][8] = 'r'; // White Rook
        }
    }
}

void CellBOARD(char Board[11][11])
{
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            Board[i][j] = '*';
        }
    }
    Board[0][0] = 'X';
    Board[0][1] = 'A';
    Board[0][2] = 'B';
    Board[0][3] = 'C';
    Board[0][4] = 'D';
    Board[0][5] = 'E';
    Board[0][6] = 'F';
    Board[0][7] = 'G';
    Board[0][8] = 'H';
    Board[1][0] = '1';
    Board[2][0] = '2';
    Board[3][0] = '3';
    Board[4][0] = '4';
    Board[5][0] = '5';
    Board[6][0] = '6';
    Board[7][0] = '7';
    Board[8][0] = '8';
    Figures(Board);
    PrintBoard(Board);
}

void Move(char Board[11][11], char FiguresP[5])
{
    int x, y, z, h;
    switch (FiguresP[0]) {
    case 'A':
        x = 1;
        break;
    case 'B':
        x = 2;
        break;
    case 'C':
        x = 3;
        break;
    case 'D':
        x = 4;
        break;
    case 'E':
        x = 5;
        break;
    case 'F':
        x = 6;
        break;
    case 'G':
        x = 7;
        break;
    case 'H':
        x = 8;
        break;
    default:
        std::cout << "Ошибка! Введите существующую клетку!" << std::endl;
        return;
    }
    switch (FiguresP[3]) {
    case 'A':
        y = 1;
        break;
    case 'B':
        y = 2;
        break;
    case 'C':
        y = 3;
        break;
    case 'D':
        y = 4;
        break;
    case 'E':
        y = 5;
        break;
    case 'F':
        y = 6;
        break;
    case 'G':
        y = 7;
        break;
    case 'H':
        y = 8;
        break;
    default:
        std::cout << "Ошибка! Введите существующую клетку!" << std::endl;
        return;
    }
    switch (FiguresP[1]) {
    case '1':
        z = 1;
        break;
    case '2':
        z = 2;
        break;
    case '3':
        z = 3;
        break;
    case '4':
        z = 4;
        break;
    case '5':
        z = 5;
        break;
    case '6':
        z = 6;
        break;
    case '7':
        z = 7;
        break;
    case '8':
        z = 8;
        break;
    default:
        std::cout << "Ошибка! Введите существующую клетку!" << std::endl;
        return;
    }
    switch (FiguresP[4]) {
    case '1':
        h = 1;
        break;
    case '2':
        h = 2;
        break;
    case '3':
        h = 3;
        break;
    case '4':
        h = 4;
        break;
    case '5':
        h = 5;
        break;
    case '6':
        h = 6;
        break;
    case '7':
        h = 7;
        break;
    case '8':
        h = 8;
        break;
    default:
        std::cout << "Ошибка! Введите существующую клетку!" << std::endl;
        return;
    }
    Board[h][y] = Board[z][x];
    Board[z][x] = '*';
    PrintBoard(Board);
}

int main()
{
    char Board[11][11];
    CellBOARD(Board);
    char FiguresP[5];
    while (true) {
        std::cout << "Введите координату клетки нужной фигуры и координату "
                     "клетки 'назначения'(пример: E2-E5): "
                  << std::endl;
        for (int i = 0; i < 5; ++i)
            std::cin >> FiguresP[i];
        Move(Board, FiguresP);
    }
    return 0;
}