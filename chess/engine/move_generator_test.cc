
//Created on 2017-5-24
//@author: linjiafanf33@163.com

#include <cstdio>

#include <memory>

#include "gtest/gtest.h"
#include "move_generator.h"
#include "board.h"
#include "piece.h"
#include "move.h"

TEST(MoveGeneratorTest, Generate) {
  std::shared_ptr<chess::Piece> rook_piece(chess::Piece::CreatePiece(12));
  typename chess::MoveGenerator::Moves rook_moves = 
    chess::MoveGenerator::GetInstance().Generate(rook_piece);

  for (auto rook_move : rook_moves) {
    if (rook_move.left_num() == 0)
      EXPECT_TRUE((-9 <= rook_move.forward_num()) && (rook_move.forward_num() <= 9));
    else {
      EXPECT_EQ(0, rook_move.forward_num());
      EXPECT_TRUE((-8 <= rook_move.left_num()) && (rook_move.left_num() <= 8));
    }
  }
}

TEST(MoveGeneratorTest, MovePiece) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadStandardBoard();

  chess::MoveGenerator& generator = chess::MoveGenerator::GetInstance();
  auto rook_location = std::make_shared<chess::Location>(1, 1);
  std::shared_ptr<chess::Piece> rook_piece = board->GetPiece(rook_location);
  typename chess::MoveGenerator::Moves rook_moves = generator.Generate(rook_piece);
  for (auto rook_move : rook_moves) {
    try {
      std::shared_ptr<chess::MoveState> rook_state = board->MakeMove(rook_location, rook_move);
      board->UnmakeMove(rook_state);
    } catch (std::out_of_range& e) {
      printf("generate rook move, %s left_num:%d forward_num:%d, throw std::out_of_range exception\n", 
        rook_location->Description().c_str(), rook_move.left_num(), rook_move.forward_num());
    }
    
  }

}


int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}