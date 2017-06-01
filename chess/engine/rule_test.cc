
//Created on 2017-05-28
//@author: linjiafang33@163.com

#include "rule.h"

#include <cstdio>

#include <memory>

#include "gtest/gtest.h"

#include "board.h"
#include "move.h"
#include "move_generator.h"
#include "move_state.h"
#include "piece.h"

namespace {
int random_board[90] = {
  0, 12,  0,  0,  8,  0,  0, 11, 12, 
  0,  0,  0,  0,  9,  0,  0,  0,  0, 
 11,  0, 13,  9, 10,  0,  0, 13,  0, 
 14,  0, 14,  0, 14,  0, 14, 21, 14, 
  0,  0,  0,  0,  0,  0, 22,  0,  0, 

  0,  0, 22, 19,  0,  0, 18,  0,  0, 
 22,  0,  0,  0, 22,  0,  0, 20, 22, 
 18,  0,  0,  0, 21,  0,  0,  0,  0, 
 20,  0,  0,  0, 17,  0,  0,  0,  0, 
  0,  0,  0, 16,  0, 17,  0, 19,  0, 
};

void MovePiece(std::shared_ptr<chess::Board> board, std::shared_ptr<chess::Location> location) {
  std::shared_ptr<chess::Piece> piece = board->GetPiece(location);
  typename chess::MoveGenerator::Moves moves = chess::MoveGenerator::GetInstance().Generate(piece);
  for (auto move : moves) {
    bool result = chess::rule::ValidMove(board, location, move);
    printf("%s at %s move left:%d forward:%d rule result:%d\n", 
      piece->Name().c_str(), location->Description().c_str(), move.left_num(), move.forward_num(), result);
  }

  printf("\n");
}

} // namespace



TEST(RuleTest, MoveRook) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(1, 2);
  MovePiece(board, location);

}

TEST(RuleTest, MoveKing) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(10, 4);
  MovePiece(board, location);
}

TEST(RuleTest, MoveHorse) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(6, 4);
  MovePiece(board, location);
}

TEST(RuleTest, MoveBishop) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location1 = std::make_shared<chess::Location>(6, 7);
  MovePiece(board, location1);

  auto location2 = std::make_shared<chess::Location>(8, 1);
  MovePiece(board, location2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}