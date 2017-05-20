
//Created on 2017-05-18
//@author: linjiafang33@163.com

#include <memory>
#include "gtest/gtest.h"
#include "piece.h"


TEST(PieceTest, CreatePieceTest) {
  EXPECT_EQ(8, chess::Piece::CreatePiece(chess::Piece::kRedKing)->piece_type());
  EXPECT_EQ(0, chess::Piece::GetEmptyPiece()->piece_type());
  //EXPECT_TRUE(chess::Piece::NotEmpty(chess::Piece::CreatePiece(chess::Piece::kBlackKing)));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}