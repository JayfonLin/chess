
//Created on 2017-05-20
//@author: linjiafang33@163.com

#include <memory>
#include "gtest/gtest.h"
#include "board.h"
#

TEST(BoardTest, CreateBoard) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  int board_table[] = {
   12, 11, 10,  9,  8,  9, 10, 11, 12, 
    0,  0,  0,  0,  0,  0,  0,  0,  0, 
    0, 13,  0,  0,  0,  0,  0, 13,  0, 
   14,  0, 14,  0, 14,  0, 14,  0, 14, 
    0,  0,  0,  0,  0,  0,  0,  0,  0, 

    0,  0,  0,  0,  0,  0,  0,  0,  0, 
   22,  0, 22,  0, 22,  0, 22,  0, 22, 
    0, 21,  0,  0,  0,  0,  0, 21,  0, 
    0,  0,  0,  0,  0,  0,  0,  0,  0, 
   20, 19, 18, 17, 16, 17, 18, 19, 20, 
  };

  for (int i = 0; i < 90; ++i) {
    EXPECT_EQ(board_table[i], board->GetPiece(i)->piece_type());
  }

}

TEST(BoardTest, MovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  std::shared_ptr<chess::Move> move(new chess::Move(1, 19));
  board->MakeMove(move);
  EXPECT_TRUE(chess::Piece::Empty(board->GetPiece(1)));
  EXPECT_EQ(11, board->GetPiece(19)->piece_type());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
