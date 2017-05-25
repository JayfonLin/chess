
//Created on 2017-05-22
//@author: linjiafang33@163.com

#include "move_state.h"

namespace chess {

MoveState::MoveState(std::shared_ptr<Piece> piece, int position, const Move& move) 
    : moved_piece_(piece), from_(position), move_(move) { }

std::shared_ptr<Piece> MoveState::moved_piece() {
  return moved_piece_;
}

void MoveState::SetKilledPiece(std::shared_ptr<Piece> piece) {
  killed_piece_ = piece;
}

std::shared_ptr<Piece> MoveState::killed_piece() {
  return killed_piece_;
}

int MoveState::from() {
  return from_;
}

int MoveState::to() {
  int line_num = 9;
  int to_position;
  if (moved_piece_->IsRed()) {
    to_position = from_ + move_.left_num();
    to_position = to_position + move_.forward_num() * line_num;
  } else {
    to_position = from_ - move_.left_num();
    to_position = to_position - move_.forward_num() * line_num;
  }

  return to_position;
}

}