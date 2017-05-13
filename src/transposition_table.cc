
//Created on 2017-05-08
//@author: linjiafang33@163.com

#include "transposition.h"

#include <cstdlib>
#include <cstdint>
#include <ctime>
#include "board.h"


int64_t Rand64() {
  return rand() 
    ^ ((int64_t)rand() << 15) 
    ^ ((int64_t)rand() << 30) 
    ^ ((int64_t)rand() << 45) 
    ^ ((int64_t)rand() << 60);
}

int32_t Rand32() {
  return rand()
    ^ ((int32_t)rand() << 15)
    ^ ((int32_t)rand() << 30);
}

namespace chess {
  void TranspositionTable::InitHashTable() {
    srand((unsigned)time(NULL));

    for (int piece_type = 0; piece_type < kPieceNumber; ++piece_type) {
      for (int position = 0; position < kBoardNumber; ++position) {
        if (!board.InBoard(position)) {
          continue;
        }

        hash_key_board_state_[piece_type][position] = Rand32();
        hash_key_board_state_[piece_type][position] = Rand64();
      }
    } 
  }



  void TranspositionTable::CalculateInitHashKey(Piece squares[]) {
    int32_t hash_32 = 0;
    int64_t hash_64 = 0;

    for (int position = 0; position < kBoardNumber; position++) {
      if (!board.InBoard(position)) {
        continue;
      }

      Piece& piece_type = squares[position];
      if (piece_type != Piece.EMPTY) {
        hash_32 = hash_32 ^ hash_key_32_[]
      }

    }
  }
}