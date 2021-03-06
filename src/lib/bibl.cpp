#include "bibl.h"
#include <iostream>
#include <math.h>
void PrintBoard(char Board[11][11]){
    for(int i = 0; i < 9; ++i){
      for(int j = 0; j < 9; ++j){
        std::cout << Board[i][j] << " ";
      }
      std::cout << std::endl;
    }
}

void Figures(char Board[11][11]){
  for(int i = 1; i < 9; i++){
      if(i == 1){
        Board[i][1] = 'R';//Black Rook
        Board[i][2] = 'H';//Black Horse
        Board[i][3] = 'B';//Black Bishop
        Board[i][4] = 'Q';//Black Queen
        Board[i][5] = 'K';//Black King
        Board[i][6] = 'B';//Black Bishop
        Board[i][7] = 'H';//Black Horse
        Board[i][8] = 'R';//Black Rook
    }
    if(i == 2){
      for(int j = 1; j < 9; j++){
        Board[i][j] = 'P';//Black pawn
      }
    }
    if(i == 7){
      for(int j = 1; j < 9; j++){
        Board[i][j] = 'p';//White pawn
      }
    }
    if(i == 8){
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

void CellBOARD(char Board[11][11]){
  for(int i = 1; i < 9; ++i){
    for(int j = 1;j < 9; ++j){
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

void Move(char Board[11][11], char FiguresP[5], int countar[8], int countar1[8]){
    int x, y, z, h;
    switch(FiguresP[0]){
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
  switch(FiguresP[3]){
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
  switch(FiguresP[1]){
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
  switch(FiguresP[4]){
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
  if(Board[z][x] == 'P'){
    if(x != y){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
    if(z > h){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
    if(countar[x] == 0){
        if((h - z) > 2){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        } else {
            countar[x] = 1;
        }
    } else {
       if((h-z ) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
       }
    }
  }
  if(Board[z][x] == 'p'){
    if(x != y){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
    if(h > z){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
    if( countar1[x] == 0){
        if((z - h) > 2){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        } else {
            countar1[x] = 1;
        }
    } else {
       if((z - h)> 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
       }
    }
  }
  if(Board[z][x] == 'R'){
    if(x != y && z != h){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'r'){
    if(x != y && z != h){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'B'){
    if(abs(y-x) != abs(h-z)){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'b'){
    if(abs(y-x) != abs(h-z)){
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'H'){
    if(y == (x+1) && h == (z+2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-1) && h == (z+2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+1) && h == (z-2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-1) && h == (z-2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+2) && h == (z-1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+2) && h == (z+1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-2) && h == (z-1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-2) && h == (z+1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
    } else {
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'h'){
    if(y == (x-1) && h == (z-2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+1) && h == (z-2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-1) && h == (z+2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+1) && h == (z+2)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-2) && h == (z+1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x-2) && h == (z-1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+2) && h == (z+1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else if(y == (x+2) && h == (z-1)){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else{
        std::cout << "Эта фигура не может так двигаться." << std::endl;
        return;
    }
  }
  if(Board[z][x] == 'Q'){
    if(x == y || z == h){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else {
        if(abs(y-x) == abs(h-z)){
            Board[h][y] = Board[z][x];
            Board[z][x] = '*';
            PrintBoard(Board);
            return;
        } else {
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    }
  }
  if(Board[z][x] == 'q'){
    if(x == y || z == h){
        Board[h][y] = Board[z][x];
        Board[z][x] = '*';
        PrintBoard(Board);
        return;
    } else {
        if(abs(y-x) == abs(h-z)){
            Board[h][y] = Board[z][x];
            Board[z][x] = '*';
            PrintBoard(Board);
            return;
        } else {
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    }
  }
  if(Board[z][x] == 'K'){
    if(x == y){
        if(abs(h-z) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    } else if (h == z) {
        if(abs(y-x) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    } else {
        if(abs(y-x) > 1 && abs(h-z) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    }
  }
  if(Board[z][x] == 'k'){
    if(x == y){
        if(abs(h-z) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    } else if (h == z) {
        if(abs(y-x) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    } else {
        if(abs(y-x) > 1 && abs(h-z) > 1){
            std::cout << "Эта фигура не может так двигаться." << std::endl;
            return;
        }
    }
  }
  Board[h][y] = Board[z][x];
  Board[z][x] = '*';
  PrintBoard(Board);
}
