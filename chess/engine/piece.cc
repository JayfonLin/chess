
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

const PieceType Piece::kEmpty = 0;
const PieceType Piece::kRedKing = 8;
const PieceType Piece::kRedBodyGuard = 9;
const PieceType Piece::kRedBishop = 10;
const PieceType Piece::kRedHorse = 11;
const PieceType Piece::kRedRook = 12;
const PieceType Piece::kRedCannon = 13;
const PieceType Piece::kRedPawn = 14;
const PieceType Piece::kBlackKing = 16;
const PieceType Piece::kBlackBodyGuard = 17;
const PieceType Piece::kBlackBishop = 18;
const PieceType Piece::kBlackHorse = 19;
const PieceType Piece::kBlackRook = 20;
const PieceType Piece::kBlackCannon = 21;
const PieceType Piece::kBlackPawn = 22;


std::shared_ptr<Piece> Piece::CreatePiece(PieceType piece_type) {
  return std::shared_ptr<Piece>(new Piece(piece_type));
}

bool Piece::Empty() {
  return piece_type_ == kEmpty;
}

std::shared_ptr<Piece> Piece::GetEmptyPiece() {
  return std::shared_ptr<Piece>(new Piece(kEmpty));
}

Piece::Piece(PieceType piece_type) : piece_type_(piece_type) { }

bool Piece::IsRed() {
  return kRedKing <= piece_type_ && piece_type_ <= kRedPawn;
}

bool Piece::IsBlack() {
  return kBlackKing <= piece_type_ && piece_type_ <= kBlackPawn;
}

PieceType Piece::piece_type() {
  return piece_type_;
}

}