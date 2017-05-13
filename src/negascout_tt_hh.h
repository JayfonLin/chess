
//Created on 2017-05-07
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_NEGASCOUT_TT_HH
#define CHESS_SRC_NEGASCOUT_TT_HH

#include <stdint.h>
#include <memory>
#include <vector>
#include "search_engine.h"


namespace chess {
struct Move;
enum class Piece : int8_t;
class TranspositionTable;

class NegaScout_TT_HH : public SearchEngine {
 public:
  virtual Move SearchBestMove(Piece* squares);
  Move Search(Piece* squares, std::share_ptr<TranspositionTable> tt);

 private:
  int NegaScout(int depth, int alpha, int beta);

};

NegaSout_TT_HH* Instance();

}
#endif
