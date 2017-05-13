
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

class TranspostionBoard {
 public:
  uint32_t GetState(const Piece& piece, int position);
  uint64_t GetChecksum(const Piece& piece, int position);

 private:
  static TranspostionBoard* GetInstance();
  const static int kHashSize = 1024 * (2 << 10);

  TranspostionBoard(); 
  TranspostionBoard(const TranspostionBoard&);
  TranspostionBoard& operator=(const TranspostionBoard&);

  uint32_t state_[kPieceNumber][kBoardNumber];
  uint64_t checksum_[kPieceNumber][kBoardNumber];

  HashItem state_table_[kHashSize];
  HashItem checksum_table_[kHashSize];

};

class TranspositionTable {
 public:
  TranspositionTable(Piece* squares);

  void HashMakeMove(Move move);
  void HashUnmakeMove(Move move, int chess_id, int cur_position[]);
  int LookupHashTable(int alpha, int beta, int depth, int table_no);
  void EnterHashTable(EntryType entry_type, short eval, short depth, int table_no);

 private:

  Piece* squares_;
  uint32_t board_state_;
  uint64_t board_checksum_;
};  
}

#endif