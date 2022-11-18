/*
 * File: KnightsTour.cpp
 * ---------------------
 * This program find a knight's tour on an N x M chessboard.
 */

#include "KnightsTour.h"

/*
 * Function: solveKnightsTour
 * Usage: solveKnightsTour(n, m);
 * ------------------------------
 * Solves the knight's tour problem for a n x m chessboard.
 */

void solveKnightsTour(int n, int m) {
   Grid<int> board(n, m);
   board[0][0] = 1;
   if (findKnightsTour(board, 0, 0, 1)) {
      displayBoard(board);
   } else {
      cout << "No tour exists for this board." << endl;
   }
}

/*
 * Function: displayBoard
 * Usage: displayBoard(board);
 * ---------------------------
 * Displays each of the squares in the board along with its sequence
 * number in the tour.
 */

void displayBoard(Grid<int> & board) {
   for (int i = board.numRows() - 1; i >= 0; i--) {
      for (int j = 0; j < board.numCols(); j++) {
         cout << " " << setw(2) << board[i][j];
      }
      cout << endl;
   }
}


bool findKnightsTour(Grid<int> & board, int row, int col, int seq){
    int next_x, next_y;
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    if(seq == board.size()) {
        return true;
    }
    for(int k = 0; k< 8; k++){
        next_x = row+xMove[k];
        next_y = col+yMove[k];
        if(next_x >= 0 && next_x < board.numRows()  && next_y >= 0 && next_y < board.numCols() && board[next_x][next_y] == 0){
            board[next_x][next_y] = seq+1;
            if(findKnightsTour(board, next_x, next_y, seq+1) == true){
                return true;
            }
            else
                board[next_x][next_y] = 0;

        }
    }
    return false;
}

