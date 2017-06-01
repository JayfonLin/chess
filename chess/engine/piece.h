
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_PIECE_H
#define CHESS_ENGINE_PIECE_H

#include <stdint.h>
#include <memory>
#include <string>

namespace chess {
typedef int8_t PieceType;

class Piece {
 public:
  enum {
    kEmpty = 0,
    kRedKing = 8,
    kRedBodyGuard = 9,
    kRedBishop = 10,
    kRedHorse = 11,
    kRedRook = 12,
    kRedCannon = 13,
    kRedPawn = 14,
    kBlackKing = 16,
    kBlackBodyGuard = 17,
    kBlackBishop = 18,
    kBlackHorse = 19,
    kBlackRook = 20,
    kBlackCannon = 21,
    kBlackPawn = 22
  };

  static std::shared_ptr<Piece> CreatePiece(PieceType piece_type);
  static std::shared_ptr<Piece> GetEmptyPiece();

  PieceType piece_type();
  bool IsRed();
  bool IsBlack();
  bool Empty();
  std::string Name();

 private:
  Piece(PieceType piece_type);

  PieceType piece_type_;
};

} // namespace chess

#endif