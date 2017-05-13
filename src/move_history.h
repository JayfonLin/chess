
//Created on 2017-05-06
//@author: jeff

#ifndef CHESS_SRC_MOVE_HISTORY_H
#define CHESS_SRC_MOVE_HISTORY_H

class MoveHistory{
 public:
  void AddMove();
  void DelMove();
  void Clean(); 
  bool Empty();
};

#endif