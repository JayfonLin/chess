
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_EVALUATION_H
#define CHESS_SRC_EVALUATION_H

#include <stdint.h>

namespace chess {
enum class Piece : int8_t;


class Evaluator {
 public:
  int64_t Evaluate(Piece squares[], bool is_red_turn, int8_t depth);
  static int GetPosValue(int sq, int pc);

 private:
  const static int kBaseValuePawn = 100;
  const static int kBaseValueBodyGuard = 250;
  const static int kBaseValueBishop = 250;
  const static int kBaseValueRook = 500;
  const static int kBaseValueHorse = 350;
  const static int kBaseValueCannon = 350;
  const static int kBaseValueKing = 10000;

  const static int kFlexibilityPawn = 15;
  const static int kFlexibilityBodyGuard = 1;
  const static int kFlexibilityBishop = 1;
  const static int kFlexibilityRook = 6;
  const static int kFlexibilityHorse = 12;
  const static int kFlexibilityCannon = 6;
  const static int kFlexibilityKing = 0;

};  
}

#endif