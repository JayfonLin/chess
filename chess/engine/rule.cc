
//Created on 2017-05-25
//@author: linjiafang33@163.com

#include "rule.h"

#include <cmath>

namespace chess {
namespace rule {

bool ValidMove(std::shared_ptr<Board> board, std::shared_ptr<Location> location, const Move& move) {
  std::shared_ptr<Piece> from_piece = board->GetPiece(location);
  if (from_piece->Empty()) {
    return false;
  }

  std::shared_ptr<Location> to_location = board->ToLocation(from_piece, location, move);
  std::shared_ptr<MoveState> move_state(new MoveState(from_piece, location, to_location, move));
  if (!board->InBounds(move_state->to())) {
    return false;
  }

  std::shared_ptr<Piece> to_piece = board->GetPiece(move_state->to());
  move_state->SetKilledPiece(to_piece);
  
  return ValidMoveState(board, move_state);
  
}

bool SameParty(std::shared_ptr<Piece> piece_a, std::shared_ptr<Piece> piece_b) {
  if (piece_a->IsRed() && piece_b->IsRed()) {
    return true;
  } else if (piece_a->IsBlack() && piece_b->IsBlack()) {
    return true;
  }

  return false;
}

bool ValidMoveState(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (SameParty(move_state->moved_piece(), move_state->killed_piece())) {
    return false;
  }

  switch (move_state->moved_piece()->piece_type()) {
    case Piece::kRedRook:
    case Piece::kBlackRook:
    {
      return IsRookMoveValid(board, move_state);
    }

    case Piece::kRedKing:
    case Piece::kBlackKing:
    {
      return IsKingMoveValid(board, move_state);
    }

    case Piece::kRedHorse:
    case Piece::kBlackHorse:
    {
      return IsHorseMoveValid(board, move_state); 
    }

    case Piece::kRedBishop:
    case Piece::kBlackBishop:
    {
      return IsBishopMoveValid(board, move_state);
    }

    case Piece::kRedBodyGuard:
    case Piece::kBlackBodyGuard:
    {
      return IsBodyGuardMoveValid(board, move_state);
    }

    case Piece::kRedCannon:
    case Piece::kBlackCannon:
    {
      return IsCannonMoveValid(board, move_state);
    }

    case Piece::kRedPawn:
    case Piece::kBlackPawn:
    {
      return IsPawnMoveValid(board, move_state);
    }

    default:
    {
      return false;
    }
  }
}

int PieceNumBetweenLine(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!move_state->IsStraight()) {
    return 0;
  }

  int number = 0;
  if (move_state->forward_num() == 0) {
    int column_diff = move_state->to()->column() - move_state->from()->column();
    int one_step = column_diff > 0 ? 1 : -1;
    for (int col = move_state->from()->column() + one_step;
        col != move_state->to()->column();
        col += one_step) {
      auto location = std::make_shared<chess::Location>(move_state->from()->row(), col);
      if (!board->GetPiece(location)->Empty()) {
        ++number;
      }
    }

  } else {
    int row_diff = move_state->to()->row() - move_state->from()->row();
    int one_step = row_diff > 0 ? 1 : -1;
    for (int row = move_state->from()->row() + one_step;
        row < move_state->to()->row();
        row += one_step) {
      auto location = std::make_shared<chess::Location>(row, move_state->from()->column());
      if (!board->GetPiece(location)->Empty()) {
        ++number;
      }
    }

  }

  return number;
}


bool IsRookMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!move_state->IsStraight()) {
    return false;
  }

  if (PieceNumBetweenLine(board, move_state) != 0) {
    return false;
  }

  return true;
}

bool IsKingMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!move_state->IsStraight()) {
    return false;
  }

  if (!HasCrossedRiver(board, move_state->moved_piece(), move_state->to())) {
    if (!(abs(move_state->left_num()) == 1 || abs(move_state->forward_num()) == 1)) {
      return false;
    }

  } else {
    if (!(move_state->killed_piece()->piece_type() == Piece::kRedKing 
      || move_state->killed_piece()->piece_type() == Piece::kBlackKing)) {
      return false;
    }

    if (PieceNumBetweenLine(board, move_state) != 0) {
      return false;
    }
  }

  if (!board->InFort(move_state->to())) {
    return false;
  }

  return true;
}

bool IsHorseMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  int leg_left = 0;
  int leg_forward = 0;
  if (move_state->forward_num() == 2) {
    if (abs(move_state->left_num()) != 1) {
      return false;
    }

    leg_forward = 1; 

  } else if (move_state->forward_num() == -2) {
    if (abs(move_state->left_num()) != 1) {
      return false;
    }

    leg_forward = -1;

  } else if (move_state->left_num() == 2) {
    if (abs(move_state->forward_num()) != 1) {
      return false;
    }

    leg_left = 1;

  } else if (move_state->left_num() == -2) {
    if (abs(move_state->forward_num()) != 1) {
      return false;
    }

    leg_left = -1;
    
  } else {
    return false;
  }

  Move move(leg_left, leg_forward);
  std::shared_ptr<chess::Location> leg_location = 
    board->ToLocation(move_state->moved_piece(), move_state->from(), move);
  if (!board->GetPiece(leg_location)->Empty()) {
    return false;
  }

  return true;
}

bool IsBishopMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!(abs(move_state->forward_num()) == 2 && abs(move_state->left_num()) == 2)) {
    return false;
  }

  int eye_left = move_state->left_num() / 2;
  int eye_forward = move_state->forward_num() / 2;
  Move move(eye_left, eye_forward);
  auto eye_location = board->ToLocation(move_state->moved_piece(), move_state->from(), move);
  if (!board->GetPiece(eye_location)->Empty()) {
    return false;
  }

  if (HasCrossedRiver(board, move_state->moved_piece(), move_state->to())) {
    return false;
  }

  return true;
}

bool IsBodyGuardMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!(abs(move_state->forward_num()) == 1 && abs(move_state->left_num()) == 1)) {
    return false;
  }

  if (!board->InFort(move_state->to())) {
    return false;
  }

  return true;
}

bool IsCannonMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (!move_state->IsStraight()) {
    return false;
  }

  int piece_num = PieceNumBetweenLine(board, move_state);
  if (1 < piece_num) {
    return false;
  }

  if (1 == piece_num) {
    if (move_state->killed_piece()->Empty()) {
      return false;
    }
  }

  if (0 == piece_num) {
    if (!move_state->killed_piece()->Empty()) {
      return false;
    }
  }

  return true;
}

bool IsPawnMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state) {
  if (HasCrossedRiver(board, move_state->moved_piece(), move_state->from())) {
    if (move_state->IsStraight() && move_state->forward_num() != -1) {
      return true;
    }
    return false;

  } else {
    if (move_state->forward_num() == 1 && move_state->left_num() == 0) {
      return true;
    }
    return false;
  }
}

bool HasCrossedRiver(std::shared_ptr<Board> board, 
  std::shared_ptr<Piece> piece, std::shared_ptr<Location> location) {

  if (piece->IsRed()) {
    if (board->InBlackHalf(location)) {
      return true;
    }

  } else if (piece->IsBlack()) {
    if (board->InRedHalf(location)) {
      return true;
    }
  }

  return false;
}

} // namespace rule
} // namespace chess