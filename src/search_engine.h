
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_SEARCH_ENGINE_H
#define CHESS_SRC_SEARCH_ENGINE_H

#include "move_generator.h"


namespace chess{
enum class Piece : int8_t;


class SearchEngine{
 public:
  void SetSearchDepth(int depth){
    search_depth_ = depth;
  }
  
  void SetEvaluator();


  virtual SearchBestMove(Piece squares[]) = 0;

 private:
  const static int kDefaultSearchDepth = 4;

  int search_depth_;
  MoveGenerator move_generator_;
};
}

#endif

