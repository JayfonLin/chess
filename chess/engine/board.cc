
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "board.h"
#include "move_state.h"


namespace chess {

static int kBoardStandard[kDroppointNumber] = {
 12, 11, 10,  9,  8,  9, 10, 11, 12, 
  0,  0,  0,  0,  0,  0,  0,  0,  0, 
  0, 13,  0,  0,  0,  0,  0, 13,  0, 
 14,  0, 14,  0, 14,  0, 14,  0, 14, 
  0,  0,  0,  0,  0,  0,  0,  0,  0, 

  0,  0,  0,  0,  0,  0,  0,  0,  0, 
 22,  0, 22,  0, 22,  0, 22,  0, 22, 
  0, 21,  0,  0,  0,  0,  0, 21,  0, 
  0,  0,  0,  0,  0,  0,  0,  0,  0, 
 20, 19, 18, 17, 16, 17, 18, 19, 20, 
};

Board::Board() {
  board_.reserve(kDroppointNumber);
}

void Board::LoadStandardBoard() {
  LoadBoard(kBoardStandard);
}

void Board::LoadBoard(int* pieces) {
  board_.clear();

  for (int position = 0; position < kDroppointNumber; ++position) {
    board_.push_back(Piece::CreatePiece(pieces[position]));
  }
}

std::shared_ptr<MoveState> Board::MakeMove(int position, const Move& move) 
    throw (piece_not_found, std::out_of_range) {
  std::shared_ptr<Piece> from_piece = GetPiece(position);
  if (from_piece->Empty()) {
    throw piece_not_found("piece not found in from-position");
  }

  std::shared_ptr<MoveState> move_state(new MoveState(from_piece, position, move));

  std::shared_ptr<Piece> to_piece = GetPiece(move_state->to());

  SetPiece(move_state->to(), from_piece);
  SetPiece(move_state->from(), Piece::GetEmptyPiece());

  move_state->SetKilledPiece(to_piece);
  return move_state;
}

void Board::UnmakeMove(std::shared_ptr<MoveState> move_state) 
    throw (invalid_move, std::out_of_range) {
  std::shared_ptr<Piece> to_piece = GetPiece(move_state->to());
  if (to_piece != move_state->moved_piece()) {
    throw invalid_move("move piece not equal to board piece");
  }

  SetPiece(move_state->to(), move_state->killed_piece());
  SetPiece(move_state->from(), to_piece);
}

std::shared_ptr<Piece> Board::GetPiece(int position) throw (std::out_of_range){
  if (!(0 <= position && position < kDroppointNumber)) {
    throw std::out_of_range("piece position out of range");
  }

  return board_[position];
}

void Board::SetPiece(int position, std::shared_ptr<Piece> piece) throw (std::out_of_range) {
  if (!(0 <= position && position < kDroppointNumber)) {
    throw std::out_of_range("piece position out of range");
  }

  board_[position] = piece;
}

}