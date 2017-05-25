
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
#include "move_state.h"


namespace chess {

const int kDroppointNumber = 90;

class Board {
 public:
  Board();
  void LoadStandardBoard();
  void LoadBoard(int* pieces);
  std::shared_ptr<MoveState> MakeMove(int position, const Move& move) throw (piece_not_found, std::out_of_range);
  void UnmakeMove(std::shared_ptr<MoveState> move_state) throw (invalid_move, std::out_of_range);
  std::shared_ptr<Piece> GetPiece(int position) throw (std::out_of_range);
  void SetPiece(int position, std::shared_ptr<Piece> piece) throw (std::out_of_range);

 private:
  
  std::vector<std::shared_ptr<Piece>> board_;

};


}

#endif