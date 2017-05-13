
//Created on 2017-05-07
//@author: linjiafang33@163.com

#ifndef CHESS_SRC_TRANSPOSITION_TABLE_H
#define CHESS_SRC_TRANSPOSITION_TABLE_H

#include <stdint.h>

#include "piece.h"
#include "board.h"


static int64_t Rand64();
static int32_t Rand32();

namespace chess {
struct Move; 

enum class EntryType {
  EXACT,
  LOWER_BOUND,
  UPPER_BOUND
};

struct HashItem {
  int64_t checksum;
  EntryType entry_type;
  short depth;
  short score;
};

class TranspositionTable {
 public:
  void CalculateInitHashKey(Piece squares[]);
  void HashMakeMove(Move move, int cur_position[]);
  void HashUnmakeMove(Move move, int chess_id, int cur_position[]);
  int LookupHashTable(int alpha, int beta, int depth, int table_no);
  void EnterHashTable(EntryType entry_type, short eval, short depth, int table_no);

 private:
  const static int kHashSize = 1024 * (2 << 10);

  void InitHashTable();

  static uint32_t hash_key_board_state_[kPieceNumber][kBoardNumber];
  static uint64_t hash_key_board_checksum_[kPieceNumber][kBoardNumber];
  static HashItem tt0_[kHashSize];
  static HashItem tt1_[kHashSize];
  
  uint32_t board_state_;
  uint64_t board_checksum_;
};  
}

#endif