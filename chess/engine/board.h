
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <vector>
#include <memory>
#include <stdexcept>

#include "exceptions.h"
#include "move.h"
#include "piece.h"


namespace chess {

const int kDroppointNumber = 90;

class Board {
 public:
  Board();
  void LoadStandardBoard();
  void LoadBoard(int* pieces);
  std::shared_ptr<Piece> MakeMove(std::shared_ptr<Move> move) throw (piece_not_found);
  std::shared_ptr<Piece> GetPiece(int position) throw (std::out_of_range);

 private:
  
  std::vector<std::shared_ptr<Piece>> board_;

};


}

#endif