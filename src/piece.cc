
//Created on 2017-05-06
//@author: linjiafang33@163.com

#include "piece.h"
#include <memory>

namespace chess {

std::shared_ptr<Piece> Piece::CreateEmpty() {
  return std::shared_ptr<Piece>(new Piece(Piece::kEmpty));
}

std::shared_ptr<Piece> Piece::CreateRedKing() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedKing));
}

std::shared_ptr<Piece> Piece::CreateRedBodyGuard() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedBodyGuard));
}

std::shared_ptr<Piece> Piece::CreateRedBishop() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedBishop));
}

std::shared_ptr<Piece> Piece::CreateRedHorse() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedHorse));
}

std::shared_ptr<Piece> Piece::CreateRedRook() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedRook));
}

std::shared_ptr<Piece> Piece::CreateRedCannon() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedCannon));
}

std::shared_ptr<Piece> Piece::CreateRedPawn() {
  return std::shared_ptr<Piece>(new Piece(Piece::kRedPawn));
}

std::shared_ptr<Piece> Piece::CreateBlackKing() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackKing));
}

std::shared_ptr<Piece> Piece::CreateBlackBodyGuard() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackBodyGuard));
}

std::shared_ptr<Piece> Piece::CreateBlackBishop() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackBishop));
}

std::shared_ptr<Piece> Piece::CreateBlackHorse() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackHorse));
}

std::shared_ptr<Piece> Piece::CreateBlackRook() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackRook));
}

std::shared_ptr<Piece> Piece::CreateBlackCannon() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackCannon));
}

std::shared_ptr<Piece> Piece::CreateBlackPawn() {
  return std::shared_ptr<Piece>(new Piece(Piece::kBlackPawn));
}

PieceType Piece::piece_type() {
  return piece_type_;
}

}