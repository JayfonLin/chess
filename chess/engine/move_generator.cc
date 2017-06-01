
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

  move_map_[Piece::kRedHorse] = GetHorseMoves();
  move_map_[Piece::kBlackHorse] = GetHorseMoves();

  move_map_[Piece::kRedBishop] = GetBishopMoves();
  move_map_[Piece::kBlackBishop] = GetBishopMoves();
}

typename MoveGenerator::Moves MoveGenerator::InitMoveArray(int move_array[][2], int size) {
  typename MoveGenerator::Moves moves;
  for (int i = 0; i < size; ++i) {
    int* element = move_array[i];
    Move move(element[0], element[1]);
    moves.push_back(move);
  }

  return moves;
}

typename MoveGenerator::Moves MoveGenerator::GetEmptyMoves() {
  typename MoveGenerator::Moves empty_moves;
  return empty_moves;
}

typename MoveGenerator::Moves MoveGenerator::GetKingMoves() {
  int king_array[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  return InitMoveArray(king_array, 4);
}

typename MoveGenerator::Moves MoveGenerator::GetRookMoves() {
  int rook_array[][2] = {
    {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9},
    {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}, {0, -8}, {0, -9},
    {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0},
    {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}, {-8, 0}
  };

  return InitMoveArray(rook_array, 34);
}

typename MoveGenerator::Moves MoveGenerator::GetHorseMoves() {
  int horse_array[][2] = {
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1},
    {2, 1},
    {1, 2}
  };

  return InitMoveArray(horse_array, 8);
}

typename MoveGenerator::Moves MoveGenerator::GetBishopMoves() {
  int move_array[][2] = {
    {-2, -2},
    {-2, 2},
    {2, -2},
    {2, 2}
  };

  return InitMoveArray(move_array, 4);
}

const typename MoveGenerator::Moves& MoveGenerator::Generate(std::shared_ptr<Piece> piece) {
  return move_map_[piece->piece_type()];
}
}