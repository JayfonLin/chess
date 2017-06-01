
//Created on 2017-05-20
//@author: linjiafang33@163.com

#include <memory>
#include <string>

#include "gtest/gtest.h"

#include "board.h"
#include "location.h"
#include "move.h"
#include "move_state.h"
#include "piece.h"


namespace {
int random_board[chess::kDroppointNumber] = {
  0, 12,  0,  0,  8,  0,  0, 11, 12, 
  0,  0,  0,  0,  9,  0,  0,  0,  0, 
 11,  0, 13,  9, 10,  0,  0, 13,  0, 
 14,  0, 14,  0, 14,  0, 14, 21, 14, 
  0,  0,  0,  0,  0,  0, 22,  0,  0, 
  0,  0, 22, 19,  0,  0,  0,  0,  0, 
 22,  0,  0,  0, 22,  0,  0,  0, 22, 
 18,  0,  0,  0, 21,  0,  0, 20,  0, 
 20,  0,  0,  0, 17,  0,  0,  0,  0, 
  0,  0,  0,  0, 16, 17,  0, 19,  0
};
} // namespace


TEST(BoardTest, CreateBoard) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  int board_table[chess::kDroppointNumber] = {
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


  for (int r = 1; r <= chess::kBoardRow; ++r) {
    for (int c = 1; c <= chess::kBoardColumn; ++c) {
      auto location = std::make_shared<chess::Location>(r, c);
      int position = (r-1) * chess::kLineCount + (c-1);
      EXPECT_EQ(board_table[position], board->GetPiece(location)->piece_type());
    }
  }
}

void MoveHelper(std::string user_case, std::shared_ptr<chess::Board> board, 
    int row, int column, int left_num, int forward_num, int target_piece_type) {
  auto location = std::make_shared<chess::Location>(row, column);
  chess::Move move(left_num, forward_num);
  std::shared_ptr<chess::MoveState> move_state = board->MakeMove(location, move);

  EXPECT_TRUE(board->GetPiece(location)->Empty());
  EXPECT_EQ(target_piece_type, board->GetPiece(move_state->to())->piece_type());
}

TEST(BoardTest, MovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  MoveHelper("move horse", board, 1, 2, 1, 2, 11);
  MoveHelper("move rook", board, 1, 1, 0, 2, 12);
  MoveHelper("move king", board, 1, 5, 0, 1, 8);
  MoveHelper("move cannon", board, 3, 2, 0, 7, 13);
  MoveHelper("move bishop", board, 10, 3, -2, 2, 18);
  MoveHelper("move bodyguard", board, 10, 6, 1, 1, 17);

}


TEST(BoardTest, InvalidMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  std::shared_ptr<chess::Location> location1(new chess::Location(2, 1));
  chess::Move move1(5, 0);
  EXPECT_THROW(board->MakeMove(location1, move1), chess::piece_not_found);

  std::shared_ptr<chess::Location> location2(new chess::Location(2, 1));
  chess::Move move2(0, 2);
  EXPECT_THROW(board->MakeMove(location2, move2), chess::piece_not_found);

}


TEST(BoardTest, UnmakeMovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  std::shared_ptr<chess::Location> horse_location(new chess::Location(1, 2));
  chess::Move move_horse(1, 2);
  std::shared_ptr<chess::MoveState> move_horse_state = board->MakeMove(horse_location, move_horse);

  board->UnmakeMove(move_horse_state);
  std::shared_ptr<chess::Location> loc_3_3(new chess::Location(3, 3));
  EXPECT_TRUE(board->GetPiece(loc_3_3)->Empty());
  EXPECT_EQ(11, board->GetPiece(horse_location)->piece_type());

  std::shared_ptr<chess::Location> cannon_location(new chess::Location(8, 8));
  chess::Move move_cannon(0, 7);
  std::shared_ptr<chess::MoveState> move_cannon_state = board->MakeMove(cannon_location, move_cannon);

  board->UnmakeMove(move_cannon_state);
  std::shared_ptr<chess::Location> loc_1_8(new chess::Location(1, 8));
  EXPECT_EQ(11, board->GetPiece(loc_1_8)->piece_type());
  EXPECT_EQ(21, board->GetPiece(cannon_location)->piece_type());

  //chess::Move move_empty(8, 0);
  //ToPosition(std::shared_ptr<Piece> piece, int position, const Move& move);
  //std::shared_ptr<chess::MoveState> move_empty_state(new chess::MoveState(chess::Piece::CreatePiece(12), 9, move_empty));
  //move_empty_state->SetKilledPiece(chess::Piece::GetEmptyPiece());
  //EXPECT_THROW(board->UnmakeMove(move_empty_state), chess::invalid_move);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
