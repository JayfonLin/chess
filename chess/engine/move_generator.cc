
//Created on 2017-05-21
//@author: linjiafang33@163.com

#include "move_generator.h"

namespace chess {
MoveGenerator& MoveGenerator::GetInstance() {
  static MoveGenerator instance;
  return instance;
}

MoveGenerator::MoveGenerator() {
  Init();
}

void MoveGenerator::Init() {
  move_map_[Piece::kEmpty] = GetEmptyMoves();

  move_map_[Piece::kRedKing] = GetKingMoves();
  move_map_[Piece::kBlackKing] = GetKingMoves();

  move_map_[Piece::kRedRook] = GetRookMoves();
  move_map_[Piece::kBlackRook] = GetRookMoves();
}

typename MoveGenerator::Moves MoveGenerator::GetEmptyMoves() {
  typename MoveGenerator::Moves empty_moves;
  return empty_moves;
}

typename MoveGenerator::Moves MoveGenerator::GetKingMoves() {
  int king_array[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  typename MoveGenerator::Moves king_moves;
  for (auto element : king_array) {
    Move move(element[0], element[1]);
    king_moves.push_back(move);
  }

  return king_moves;
}

typename MoveGenerator::Moves MoveGenerator::GetRookMoves() {
  int rook_array[][2] = {
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9},
    {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}, {0, -8}, {0, -9},
    {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0},
    {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}, {-8, 0}, {-9, 0}
  };

  typename MoveGenerator::Moves rook_moves;
  for (auto element : rook_array) {
    Move move(element[0], element[1]);
    rook_moves.push_back(move);
  }

  return rook_moves;
}


const typename MoveGenerator::Moves& MoveGenerator::Generate(std::shared_ptr<Piece> piece) {
  return move_map_[piece->piece_type()];
}
}