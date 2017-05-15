
//Created on 2017-05-06
//@author: linjiafang33@163.com

#include "piece.h"
#include <memory>

namespace chess {

//Piece* Piece::CreateEmpty() {return new Piece(Piece::kEmpty);}
//Piece* Piece::CreateRedKing() {return new Piece(Piece::kRedKing);}
//std::shared_ptr<Piece> Piece::CreateRedBodyGuard() {return new Piece(Piece::kRedBodyGuard);}
//std::shared_ptr<Piece> Piece::CreateRedBishop() {return new Piece(Piece::kRedBishop);}
//std::shared_ptr<Piece> Piece::CreateRedHorse() {return new Piece(Piece::kRedHorse);}
//std::shared_ptr<Piece> Piece::CreateRedRook() {return new Piece(Piece::kRedRook);}
//std::shared_ptr<Piece> Piece::CreateRedCannon() {return new Piece(Piece::kRedCannon);}
//std::shared_ptr<Piece> Piece::CreateRedPawn() {return new Piece(Piece::kRedPawn);}
//std::shared_ptr<Piece> Piece::CreateBlackKing() {return new Piece(Piece::kBlackKing);}
//std::shared_ptr<Piece> Piece::CreateBlackBodyGuard() {return new Piece(Piece::kBlackBodyGuard);}
//std::shared_ptr<Piece> Piece::CreateBlackBishop() {return new Piece(Piece::kBlackBishop);}
//std::shared_ptr<Piece> Piece::CreateBlackHorse() {return new Piece(Piece::kBlackHorse);}
//std::shared_ptr<Piece> Piece::CreateBlackRook() {return new Piece(Piece::kBlackRook);}
//std::shared_ptr<Piece> Piece::CreateBlackCannon() {return new Piece(Piece::kBlackCannon);}
//std::shared_ptr<Piece> Piece::CreateBlackPawn() {return new Piece(Piece::kBlackPawn);}

std::shared_ptr<Piece> Piece::CreatePiece(PieceType piece_type) {
  if (piece_type == kEmpty) {
    return GetEmptyPiece();
  }

  return std::shared_ptr<Piece>(new Piece(piece_type));
}

bool Piece::NotEmpty(std::shared_ptr<Piece> piece) {
  return piece->piece_type() != kEmpty;
}

std::shared_ptr<Piece> Piece::GetEmptyPiece() {
  static Piece empty(kEmpty);
  return std::shared_ptr<Piece>(&empty);
}

Piece::Piece(PieceType piece_type) : piece_type_(piece_type) { }

PieceType Piece::piece_type() {
  return piece_type_;
}

}