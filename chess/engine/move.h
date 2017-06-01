
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

  int left_num() const;
  int forward_num() const;

 private:
  int left_num_;
  int forward_num_;
};
}

#endif