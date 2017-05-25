
//Created on 2017-05-14
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_MOVE_H
#define CHESS_ENGINE_MOVE_H

#include <memory>

namespace chess {
class Piece;

class Move {
 public:
  Move(int left, int forward);

  int left_num();
  int forward_num();

 private:
  int left_num_;
  int forward_num_;
};
}

#endif