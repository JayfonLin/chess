
//Created on 2017-05-06
//@author: linjiafang33@163.com

#include "piece.h"

namespace chess {
enum class Piece : int8_t {
  EMPTY = 0,

  RED_KING = 8,
  RED_BODYGUARD = 9,
  RED_BISHOP = 10,
  RED_HORSE = 11,
  RED_ROOK = 12,
  RED_CANNON = 13,
  RED_PAWN = 14,

  BLACK_KING = 16,
  BLACK_BODYGUARD = 17,
  BLACK_BISHOP = 18,
  BLACK_HORSE = 19,
  BLACK_ROOK = 20,
  BLACK_CANNON = 21,
  BLACK_PAWN = 22
};  
}