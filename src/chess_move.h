
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_CHESS_MOVE_H
#define CHESS_SRC_CHESS_MOVE_H

#include "piece.h"

namespace chess {
struct Move {
  Piece piece_id;
  int32_t move;
};

}

#endif