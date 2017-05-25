
//Created on 2017-05-20
//@author: linjiafang33@163.com

#include <memory>
#include <string>
#include "gtest/gtest.h"
#include "board.h"
#include "piece.h"
#include "move.h"
#include "move_state.h"


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

void MoveHelper(std::string user_case, std::shared_ptr<chess::Board> board, int position, int right_num, int forward_num, int target_piece_type) {
  chess::Move move(right_num, forward_num);
  std::shared_ptr<chess::MoveState> move_state = board->MakeMove(position, move);

  EXPECT_TRUE(board->GetPiece(position)->Empty());
  EXPECT_EQ(target_piece_type, board->GetPiece(move_state->to())->piece_type());
}

TEST(BoardTest, MovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  MoveHelper("move horse", board, 1, 1, 2, 11);
  MoveHelper("move rook", board, 0, 0, 2, 12);
  MoveHelper("move king", board, 4, 0, 1, 8);
  MoveHelper("move cannon", board, 19, 0, 7, 13);
  MoveHelper("move bishop", board, 83, -2, 2, 18);
  MoveHelper("move bodyguard", board, 86, 1, 1, 17);

}


TEST(BoardTest, InvalidMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  chess::Move move1(5, 0);
  EXPECT_THROW(board->MakeMove(9, move1), chess::piece_not_found);

  chess::Move move2(0, 2);
  EXPECT_THROW(board->MakeMove(9, move2), chess::piece_not_found);

}


TEST(BoardTest, UnmakeMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  chess::Move move_horse(1, 2);
  std::shared_ptr<chess::MoveState> move_horse_state = board->MakeMove(1, move_horse);

  board->UnmakeMove(move_horse_state);
  EXPECT_TRUE(board->GetPiece(20)->Empty());
  EXPECT_EQ(11, board->GetPiece(1)->piece_type());

  chess::Move move_cannon(0, 7);
  std::shared_ptr<chess::MoveState> move_cannon_state = board->MakeMove(70, move_cannon);

  board->UnmakeMove(move_cannon_state);
  EXPECT_EQ(11, board->GetPiece(7)->piece_type());
  EXPECT_EQ(21, board->GetPiece(70)->piece_type());

  chess::Move move_empty(8, 0);
  std::shared_ptr<chess::MoveState> move_empty_state(new chess::MoveState(chess::Piece::CreatePiece(12), 9, move_empty));
  move_empty_state->SetKilledPiece(chess::Piece::GetEmptyPiece());
  EXPECT_THROW(board->UnmakeMove(move_empty_state), chess::invalid_move);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
