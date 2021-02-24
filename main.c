#include <iostream>
#include <string.h>
using namespace std;

char Board[11][11];
char Figure[1], CellLetter[1], FigureCoorI[1];
int CellNumber = 0, z = 0, g = 0, FigureCoorJ, count = 0;

void CellBOARD() {
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            Board[i][j] = '*';
        }
    }
}

void Figures() {
    for (int i = 1; i < 9; i++) {
        if (i == 1) {
            Board[i][1] = 'R';//Black Rook
            Board[i][2] = 'H';//Black Horse
            Board[i][3] = 'B';//Black Bishop
            Board[i][4] = 'Q';//Black Queen
            Board[i][5] = 'K';//Black King
            Board[i][6] = 'B';//Black Bishop
            Board[i][7] = 'H';//Black Horse
            Board[i][8] = 'R';//Black Rook
        }
        if (i == 2) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'P';//Black pawn
            }
        }
        if (i == 7) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'p';//White pawn
            }
        }
        if (i == 8) {
            Board[i][1] = 'r';//White Rook
            Board[i][2] = 'h';//White Horse
            Board[i][3] = 'b';//White Bishop
            Board[i][4] = 'q';//White Queen
            Board[i][5] = 'k';//White King
            Board[i][6] = 'b';//White Bishop
            Board[i][7] = 'h';//White Horse
            Board[i][8] = 'r';//White Rook
        }
    }
}

void Stroke() {
    for (int i = 1; i < 9; i++) {
        if (i == 1) {
            Board[i][1] = 'R';//Black Rook
            Board[i][2] = 'H';//Black Horse
            Board[i][3] = 'B';//Black Bishop
            Board[i][4] = 'Q';//Black Queen
            Board[i][5] = 'K';//Black King
            Board[i][6] = 'B';//Black Bishop
            Board[i][7] = 'H';//Black Horse
            Board[i][8] = 'R';//Black Rook
        }
        if (i == 2) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'P';//Black pawn
            }
        }
        if (i == 7) {
            for (int j = 1; j < 9; j++) {
                Board[i][j] = 'p';//White pawn
            }
        }
        if (i == 8) {
            Board[i][1] = 'r';//White Rook
            Board[i][2] = 'h';//White Horse
            Board[i][3] = 'b';//White Bishop
            Board[i][4] = 'q';//White Queen
            Board[i][5] = 'k';//White King
            Board[i][6] = 'b';//White Bishop
            Board[i][7] = 'h';//White Horse
            Board[i][8] = 'r';//White Rook
        }
    }
    switch (CellLetter[1]) {
    case 'A':
        z = 1;
        break;
    case 'B':
        z = 2;
        break;
    case 'C':
        z = 3;
        break;
    case 'D':
        z = 4;
        break;
    case 'E':
        z = 5;
        break;
    case 'F':
        z = 6;
        break;
    case 'G':
        z = 7;
        break;
    case 'H':
        z = 8;
        break;
    }
    if (count == 1) {
        int ii = 1, jj = 1;
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (Board[i][j] == Figure[1]) {
                    ii = i;
                    jj = j;
                }
            }
        }
        Board[z][CellNumber] = Board[ii][jj];
        Board[ii][jj] = '*';
    }
    else {
        Board[z][CellNumber] = Board[g][FigureCoorJ];
        Board[g][FigureCoorJ] = '*';
    }
}

void RepeatedShapes() {
    count = 0;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (Board[i][j] == Figure[1]) {
                count++;
            }
        }
    }
    if (count > 1) {
        cout << "Enter letter cell: ";
        cin >> FigureCoorI[1];
        cout << "Enter cell number: ";
        cin >> FigureCoorJ;
    }
    switch (FigureCoorI[1]) {
    case 'A':
        g = 1;
        break;
    case 'B':
        g = 2;
        break;
    case 'C':
        g = 3;
        break;
    case 'D':
        g = 4;
        break;
    case 'E':
        g = 5;
        break;
    case 'F':
        g = 6;
        break;
    case 'G':
        g = 7;
        break;
    case 'H':
        g = 8;
        break;
    }
}


int main() {
    CellBOARD();
    Figures();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
    while (true) {
        cout << endl;
        cout << "Enter name figure: ";
        cin >> Figure[1];
        RepeatedShapes();
        cout << "Enter the cell letter where you want to place the figure: ";
        cin >> CellLetter[1];
        cout << "Enter the cell number where you want to place the figure: ";
        cin >> CellNumber;
        if (CellNumber > 8 || CellNumber == 0) {
            cout << "EROR";
            continue;
        }
        cout << endl;
        Stroke();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                cout << Board[i][j] << " ";
            }
            cout << endl;
        }
    }
}