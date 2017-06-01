
//Created on 2017-05-06
//@author: linjiafang33@163.com

#include "piece.h"
#include <memory>

namespace chess {

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

std::string Piece::Name() {
  switch (piece_type_) {
    case kRedKing:
      return std::string("Red-King");
    case kRedRook:
      return std::string("Red-Rook");
    case kRedHorse:
      return std::string("Red-Horse");
    case kRedBishop:
      return std::string("Red-Bishop");
    case kRedBodyGuard:
      return std::string("Red-BodyGuard");
    case kRedCannon:
      return std::string("Red-Cannon");
    case kRedPawn:
      return std::string("Red-Pawn");

    case kBlackKing:
      return std::string("Black-King");
    case kBlackRook:
      return std::string("Black-Rook");
    case kBlackHorse:
      return std::string("Black-Horse");
    case kBlackBishop:
      return std::string("Black-Bishop");
    case kBlackBodyGuard:
      return std::string("Black-BodyGuard");
    case kBlackCannon:
      return std::string("Black-Cannon");
    case kBlackPawn:
      return std::string("Black-Pawn");
      
    case kEmpty:
    default:
      return std::string("Empty-Piece");
  }
}

} // namespace chess