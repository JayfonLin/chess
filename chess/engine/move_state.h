
//Created on 2017-05-22
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_MOVE_STATE_H
#define CHESS_ENGINE_MOVE_STATE_H

#include <memory>
#include "move.h"
#include "piece.h"


namespace chess {
class MoveState {
 public:
  MoveState(std::shared_ptr<Piece> piece, int position, const Move& move);
  std::shared_ptr<Piece> moved_piece();
  void SetKilledPiece(std::shared_ptr<Piece> piece);
  std::shared_ptr<Piece> killed_piece();
  int from();
  int to();

 private:
  Move move_;
  int from_;
  int to_;
  std::shared_ptr<Piece> moved_piece_;
  std::shared_ptr<Piece> killed_piece_;
};
}

#endif