
//Created on 2017-05-20
//@author: linjiafang33@163.com

#include <memory>
#include <string>
#include "gtest/gtest.h"
#include "board.h"
#include "piece.h"


TEST(BoardTest, CreateBoard) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  int board_table[] = {
/* 0 */    12, 11, 10,  9,  8,  9, 10, 11, 12, 
/* 9 */     0,  0,  0,  0,  0,  0,  0,  0,  0, 
/* 18 */    0, 13,  0,  0,  0,  0,  0, 13,  0, 
/* 27 */   14,  0, 14,  0, 14,  0, 14,  0, 14, 
/* 36 */    0,  0,  0,  0,  0,  0,  0,  0,  0, 

/* 45 */    0,  0,  0,  0,  0,  0,  0,  0,  0, 
/* 54 */   22,  0, 22,  0, 22,  0, 22,  0, 22, 
/* 63 */    0, 21,  0,  0,  0,  0,  0, 21,  0, 
/* 72 */    0,  0,  0,  0,  0,  0,  0,  0,  0, 
/* 81 */   20, 19, 18, 17, 16, 17, 18, 19, 20, 
  };

  for (int i = 0; i < 90; ++i) {
    EXPECT_EQ(board_table[i], board->GetPiece(i)->piece_type());
  }

}

void MoveHelper(std::string user_case, std::shared_ptr<chess::Board> board, int from, int to, int target_piece_type) {
  std::shared_ptr<chess::Move> move(new chess::Move(from, to));
  board->MakeMove(move);
  EXPECT_TRUE(chess::Piece::Empty(board->GetPiece(from)));
  EXPECT_EQ(target_piece_type, board->GetPiece(to)->piece_type());
}

TEST(BoardTest, MovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  MoveHelper("move horse", board, 1, 20, 11);
  MoveHelper("move rook", board, 0, 17, 12);
  MoveHelper("move king", board, 4, 13, 8);
  MoveHelper("move cannon", board, 19, 82, 13);
  MoveHelper("move bishop", board, 83, 63, 18);
  MoveHelper("move bodyguard", board, 86, 76, 17);

}

TEST(BoardTest, InvalidMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  std::shared_ptr<chess::Move> move1(new chess::Move(9, 14));
  EXPECT_THROW(board->MakeMove(move1), chess::piece_not_found);

  std::shared_ptr<chess::Move> move2(new chess::Move(9, 27));
  EXPECT_THROW(board->MakeMove(move2), chess::piece_not_found);
}

TEST(BoardTest, UnmakeMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  std::shared_ptr<chess::Move> move_horse(new chess::Move(1, 20));
  board->MakeMove(move_horse);
  EXPECT_TRUE(chess::Piece::Empty(board->GetPiece(1)));
  EXPECT_EQ(11, board->GetPiece(20)->piece_type());

  board->UnmakeMove(move_horse);
  EXPECT_TRUE(chess::Piece::Empty(board->GetPiece(20)));
  EXPECT_EQ(11, board->GetPiece(1)->piece_type());

  std::shared_ptr<chess::Move> move_cannon(new chess::Move(70, 7));
  board->MakeMove(move_cannon);
  EXPECT_TRUE(chess::Piece::Empty(board->GetPiece(70)));
  EXPECT_EQ(21, board->GetPiece(7)->piece_type());

  board->UnmakeMove(move_cannon);
  EXPECT_EQ(11, board->GetPiece(7)->piece_type());
  EXPECT_EQ(21, board->GetPiece(70)->piece_type());

  std::shared_ptr<chess::Move> move_empty(new chess::Move(9, 17));
  move_empty->SetMovePiece(chess::Piece::CreatePiece(12));
  EXPECT_THROW(board->UnmakeMove(move_empty), chess::invalid_move);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
