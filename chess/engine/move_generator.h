
//Creatd on 2017-05-21
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_MOVE_GENERATOR_H
#define CHESS_ENGINE_MOVE_GENERATOR_H

#include <vector>
#include <memory>
#include <map>
#include "move.h"
#include "piece.h"

namespace chess {
class MoveGenerator {
 public:
  typedef std::vector<Move> Moves;

  static MoveGenerator& GetInstance();

  const Moves& Generate(std::shared_ptr<Piece> piece);

 private:
  MoveGenerator();
  MoveGenerator(const MoveGenerator&);
  MoveGenerator& operator=(const MoveGenerator&);

  void Init();
  Moves GetEmptyMoves();
  Moves GetKingMoves();
  Moves GetRookMoves();
  Moves GetHorseMoves();
  Moves GetBishopMoves();

  Moves InitMoveArray(int move_array[][2], int size);

  std::map<PieceType, Moves> move_map_;

};

}

#endif