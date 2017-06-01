
//Created on 2017-05-22
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_MOVE_STATE_H
#define CHESS_ENGINE_MOVE_STATE_H

#include <memory>

#include "location.h"
#include "move.h"
#include "piece.h"


namespace chess {
class MoveState {
 public:
  MoveState(std::shared_ptr<Piece> piece, std::shared_ptr<Location> from, std::shared_ptr<Location> to, const Move& move);
  std::shared_ptr<Piece> moved_piece();
  void SetKilledPiece(std::shared_ptr<Piece> piece);
  std::shared_ptr<Piece> killed_piece();

  std::shared_ptr<Location> from() {
    return from_;
  }

  std::shared_ptr<Location> to() {
    return to_;
  }

  int left_num();
  int forward_num();
  bool IsStraight();

 private:

  std::shared_ptr<Piece> moved_piece_;
  std::shared_ptr<Location> from_;
  std::shared_ptr<Location> to_;
  Move move_;
  std::shared_ptr<Piece> killed_piece_;
};
} // namespace chess

#endif