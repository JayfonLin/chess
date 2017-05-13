
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_BOARD_H
#define CHESS_SRC_BOARD_H


namespace chess {
enum class Piece: int8_t;
struct Move;

const int kBoardNumber = 256;

class Board{
 public:
  void LoadBoard(const Piece* board);
  void LoadStartupBoard();
  Piece MakeMove(Move move);
  void UnmakeMove();
  bool CanUnMakeMove();
  Move GetLastMove();
  Piece* GetCurrentBoard();

 private:
  
  Piece current_board_[kBoardNumber];

};

namespace board {
  bool InBoard(int piece_position);
}

}

#endif