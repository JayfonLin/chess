
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
  TranspositionBoard* TranspositionBoard::GetInstance() {
    static TranspositionBoard instance;
    return &instance;
  }

  TranspositionBoard::TranspositionBoard() {
    srand((unsigned)time(NULL));
  
    for (int piece_type = 0; piece_type < kPieceNumber; piece_type++) {
      for (int position = 0; position < kBoardNumber; position++]){
        if (!CChessUtil::InBoard(position)) {
          continue;
        }

        state_[piece_type][position] = Rand32();
        checksum_[piece_type][position] = Rand64();
      }
    }
  }

  uint32_t TranspositionBoard::GetState(const Piece& piece, int position) {
    return state_[piece.piece_type()][position];
  }

  uint64_t TranspositionBoard::GetChecksum(const Piece& piece, int position) {
    return checksum_[pice.piece_type()][position];
  }

  TranspositionTable::TranspositionTable(Piece* squares) 
      : squares_(squares),
        board_state_(0), 
        board_checksum_(0) {

    TranspositionBoard* trans_board = TranspositionBoard::GetInstance();
    for (int position = 0; position < kBoardNumber; position++) {
      if (!board::InBoard(position)) {
        continue;
      }

      Piece& piece_type = squares_[position];
      if (piece_type != Piece.EMPTY) {
        board_state_ ^= trans_board.GetState(piece_type, position);
        board_checksum_ ^= trans_board.GetChecksum(piece_type, position);
      }

    }
  }

}