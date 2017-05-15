
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_PIECE_H
#define CHESS_ENGINE_PIECE_H

#include <stdint.h>
#include <memory>

namespace chess {
typedef int8_t PieceType;

class Piece {
 public:
  const static PieceType kEmpty = 0;
  const static PieceType kRedKing = 8;
  const static PieceType kRedBodyGuard = 9;
  const static PieceType kRedBishop = 10;
  const static PieceType kRedHorse = 11;
  const static PieceType kRedRook = 12;
  const static PieceType kRedCannon = 13;
  const static PieceType kRedPawn = 14;
  const static PieceType kBlackKing = 16;
  const static PieceType kBlackBodyGuard = 17;
  const static PieceType kBlackBishop = 18;
  const static PieceType kBlackHorse = 19;
  const static PieceType kBlackRook = 20;
  const static PieceType kBlackCannon = 21;
  const static PieceType kBlackPawn = 22;

  static std::shared_ptr<Piece> CreatePiece(PieceType piece_type);
  static bool NotEmpty(std::shared_ptr<Piece> piece);
  static std::shared_ptr<Piece> GetEmptyPiece();

  //static std::shared_ptr<Piece> CreateEmpty();
  //static std::shared_ptr<Piece> CreateRedKing(); 
  //static std::shared_ptr<Piece> CreateRedBodyGuard(); 
  //static std::shared_ptr<Piece> CreateRedBishop(); 
  //static std::shared_ptr<Piece> CreateRedHorse(); 
  //static std::shared_ptr<Piece> CreateRedRook(); 
  //static std::shared_ptr<Piece> CreateRedCannon(); 
  //static std::shared_ptr<Piece> CreateRedPawn(); 
  //static std::shared_ptr<Piece> CreateBlackKing(); 
  //static std::shared_ptr<Piece> CreateBlackBodyGuard(); 
  //static std::shared_ptr<Piece> CreateBlackBishop(); 
  //static std::shared_ptr<Piece> CreateBlackHorse(); 
  //static std::shared_ptr<Piece> CreateBlackRook(); 
  //static std::shared_ptr<Piece> CreateBlackCannon(); 
  //static std::shared_ptr<Piece> CreateBlackPawn(); 

  PieceType piece_type();

 private:
  Piece(PieceType piece_type);

  PieceType piece_type_;
};

}

#endif