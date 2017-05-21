
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "move.h"

namespace chess {

Move::Move(int from, int to) : from_(from), to_(to){
}

void Move::SetMovePiece(std::shared_ptr<Piece> piece) {
  move_piece_ = piece;
}

std::shared_ptr<Piece> Move::move_piece() {
  return move_piece_;
}

void Move::SetKilledPiece(std::shared_ptr<Piece> piece) {
  killed_piece_ = piece;
}

std::shared_ptr<Piece> Move::killed_piece() {
  return killed_piece_;
}

int Move::from() {
  return from_;
}

int Move::to() {
  return to_;
}

}