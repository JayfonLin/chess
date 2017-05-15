
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "move.h"

namespace chess {

void Move::SetPiece(std::shared_ptr<Piece> piece) {
  piece_ = piece;
}

std::shared_ptr<Piece> Move::piece() {
  return piece_;
}

int Move::from() {
  return from_;
}

int Move::to() {
  return to_;
}

}