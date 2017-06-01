
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "move.h"

namespace chess {

Move::Move(int left, int forward) 
    : left_num_(left), forward_num_(forward) {
}

int Move::left_num() const {
  return left_num_;
}

int Move::forward_num() const {
  return forward_num_;
}

}