
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
  const static PieceType kEmpty;
  const static PieceType kRedKing;
  const static PieceType kRedBodyGuard;
  const static PieceType kRedBishop;
  const static PieceType kRedHorse;
  const static PieceType kRedRook; 
  const static PieceType kRedCannon;
  const static PieceType kRedPawn;
  const static PieceType kBlackKing;
  const static PieceType kBlackBodyGuard;
  const static PieceType kBlackBishop;
  const static PieceType kBlackHorse;
  const static PieceType kBlackRook;
  const static PieceType kBlackCannon;
  const static PieceType kBlackPawn;

  static std::shared_ptr<Piece> CreatePiece(PieceType piece_type);
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
  bool IsRed();
  bool IsBlack();
  bool Empty();

 private:
  Piece(PieceType piece_type);

  PieceType piece_type_;
};

}

#endif