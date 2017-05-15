
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <vector>
#include <memory>

#include "exceptions.h"


namespace chess {
class Piece;
class Move;

const int kDroppointNumber = 90;

class Board {
 public:
  Board();
  void LoadStandardBoard();
  void LoadBoard(int* pieces);
  std::shared_ptr<Piece> MakeMove(std::shared_ptr<Move> move) throw (piece_not_found);

 private:
  
  std::vector<std::shared_ptr<Piece>> board_;

};


}

#endif