
//Created on 2017-05-22
//@author: linjiafang33@163.com

#include "move_state.h"

namespace chess {

MoveState::MoveState(std::shared_ptr<Piece> piece, std::shared_ptr<Location> from, std::shared_ptr<Location> to, const Move& move)
    : moved_piece_(piece), from_(from), to_(to), move_(move) { }

std::shared_ptr<Piece> MoveState::moved_piece() {
  return moved_piece_;
}

void MoveState::SetKilledPiece(std::shared_ptr<Piece> piece) {
  killed_piece_ = piece;
}

std::shared_ptr<Piece> MoveState::killed_piece() {
  return killed_piece_;
}

int MoveState::left_num() {
  return move_.left_num();
  
}

int MoveState::forward_num() {
  return move_.forward_num();
}

bool MoveState::IsStraight() {
  if (move_.left_num() == 0 && move_.forward_num() != 0) {
    return true;
  } else if (move_.forward_num() == 0 && move_.left_num() != 0) {
    return true;
  }

  return false;
}
} // namespace chess