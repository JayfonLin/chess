
//Created on 2017-05-14
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_MOVE_H
#define CHESS_ENGINE_MOVE_H

#include <memory>

namespace chess {
class Piece;

class Move {
 public:
  void SetPiece(std::shared_ptr<Piece> piece);
  std::shared_ptr<Piece> piece();
  int from();
  int to();

 private:
  std::shared_ptr<Piece> piece_;
  int from_;
  int to_;
};
}

#endif