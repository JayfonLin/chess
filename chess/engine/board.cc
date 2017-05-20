
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "board.h"


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

std::shared_ptr<Piece> Board::MakeMove(std::shared_ptr<Move> move) throw (piece_not_found){
  std::shared_ptr<Piece> from_piece = board_[move->from()];
  if (Piece::Empty(from_piece)) {
    throw piece_not_found("piece not found");
  }

  board_[move->to()] = from_piece;
  board_[move->from()] = Piece::GetEmptyPiece();

  move->SetPiece(from_piece);
  return from_piece;
}

std::shared_ptr<Piece> Board::GetPiece(int position) throw (std::out_of_range){
  if (!(0 <= position && position < kDroppointNumber)) {
    throw std::out_of_range("piece position out of range");
  }

  return board_[position];
}

}