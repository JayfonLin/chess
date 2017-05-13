
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_MOVE_GENERATOR_H
#define CHESS_SRC_MOVE_GENERATOR_H

namespace chess {
class MoveGenerator {
 public:
  int CreatePossibleMove(int squares[], int mvs[], int ply, int side);
  static int* GenKingMoves(int squares[], int sq_src, int side, bool illeagal);
  static int* GenBodyguardMoves(int squares[], int sq_src, int side, bool illeagal);
  static int* GenBishopMoves(int squares[], int sq_src, int side, int illeagal);
  static int* GenHorseMoves(int squares[], int sq_src, int side, int illeagal);
  static int* GenRookMoves(int squares[], int sq_src, int side, int illeagal);
  static int* GenCannonMoves(int squares[], int sq_src, int side, int illeagal);
  static int* GenPawnMoves(int squares[], int sq_src, int side, int illeagal);
  static int GenKingFace(int squares[], int sq_src);
  static bool LegalMove(int squares[], int mv, int side);

 private:
  static bool LegalKingFace(int squares[], int mv);
   
};
}

#endif