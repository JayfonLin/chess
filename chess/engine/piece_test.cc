
//Created on 2017-05-18
//@author: linjiafang33@163.com

#include <memory>
#include "gtest/gtest.h"
#include "piece.h"


TEST(PieceTest, CreatePiece) {
  EXPECT_EQ(8, chess::Piece::CreatePiece(chess::Piece::kRedKing)->piece_type());
  EXPECT_EQ(22, chess::Piece::CreatePiece(chess::Piece::kBlackPawn)->piece_type());
  EXPECT_EQ(0, chess::Piece::GetEmptyPiece()->piece_type());
}

TEST(PieceTest, CreateTwice) {
  EXPECT_EQ(20, chess::Piece::CreatePiece(chess::Piece::kBlackRook)->piece_type());
  EXPECT_EQ(20, chess::Piece::CreatePiece(chess::Piece::kBlackRook)->piece_type());
}

TEST(PieceTest, Empty) {
  EXPECT_TRUE(!chess::Piece::CreatePiece(chess::Piece::kBlackKing)->Empty());
  EXPECT_TRUE(chess::Piece::GetEmptyPiece()->Empty());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}