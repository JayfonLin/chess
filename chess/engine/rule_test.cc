
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

int king_board[90] = {
  0, 12,  0,  8,  0,  0,  0, 11, 12, 
  0,  0,  0,  0,  9,  0,  0,  0,  0, 
 11,  0, 13,  0, 10,  0,  0, 13,  0, 
 14,  0, 14,  0, 14,  0, 14, 21, 14, 
  0,  0,  0,  0,  0,  0, 22,  0,  0, 

  0,  0, 22,  0,  0,  0, 18,  0,  0, 
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

void MovePieceWithMove(std::shared_ptr<chess::Board> board,
  std::shared_ptr<chess::Location> location, const chess::Move& move) {

  std::shared_ptr<chess::Piece> piece = board->GetPiece(location);
  bool result = chess::rule::ValidMove(board, location, move);
  printf("%s at %s move left:%d forward:%d rule result:%d\n", 
    piece->Name().c_str(), location->Description().c_str(), move.left_num(), move.forward_num(), result);

  printf("\n");
}

} // namespace



TEST(RuleTest, MoveRook) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(1, 2);
  MovePiece(board, location);

  chess::Move move1(1, 3);
  MovePieceWithMove(board, location, move1);

  chess::Move move2(0, 0);
  MovePieceWithMove(board, location, move2);

  chess::Move move3(5, 20);
  MovePieceWithMove(board, location, move3);
}

TEST(RuleTest, MoveKing) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(10, 4);
  MovePiece(board, location);

  chess::Move move1(0, 9);
  MovePieceWithMove(board, location, move1);

  std::shared_ptr<chess::Board> board2(new chess::Board());
  board2->LoadBoard(king_board);
  MovePieceWithMove(board2, location, move1);
}

TEST(RuleTest, MoveHorse) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(6, 4);
  MovePiece(board, location);

  chess::Move move1(1, 3);
  MovePieceWithMove(board, location, move1);

  chess::Move move2(2, 0);
  MovePieceWithMove(board, location, move2);
}

TEST(RuleTest, MoveBishop) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location1 = std::make_shared<chess::Location>(6, 7);
  MovePiece(board, location1);

  auto location2 = std::make_shared<chess::Location>(8, 1);
  MovePiece(board, location2);

  chess::Move move1(0, -2);
  MovePieceWithMove(board, location1, move1);

  chess::Move move2(2, 0);
  MovePieceWithMove(board, location1, move2);
}

TEST(RuleTest, MoveBodyGuard) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(9, 5);
  MovePiece(board, location);  

  chess::Move move1(1, 0);
  MovePieceWithMove(board, location, move1);

  chess::Move move2(0, -1);
  MovePieceWithMove(board, location, move2);
}

TEST(RuleTest, MoveCannon) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location = std::make_shared<chess::Location>(3, 8);
  MovePiece(board, location);  

  chess::Move move1(-3, 4);
  MovePieceWithMove(board, location, move1);
}

TEST(RuleTest, MovePawn) {
  std::shared_ptr<chess::Board> board(new chess::Board());
  board->LoadBoard(random_board);

  auto location1 = std::make_shared<chess::Location>(5, 7);
  MovePiece(board, location1);

  auto location2 = std::make_shared<chess::Location>(4, 3);
  MovePiece(board, location2);  

  chess::Move move1(0, 2);
  MovePieceWithMove(board, location2, move1);

  auto location3 = std::make_shared<chess::Location>(6, 3);
  chess::Move move2(0, -1);
  MovePieceWithMove(board, location3, move2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}