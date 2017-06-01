
//Created on 2017-05-06
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <memory>
#include <stdexcept>
#include <vector>

#include "exceptions.h"
#include "location.h"
#include "move.h"
#include "move_state.h"
#include "piece.h"



namespace chess {

const int kDroppointNumber = 90;
const int kUpperHalfEnd = 44;
const int kLineCount = 9;
const int kBoardRow = 10;
const int kBoardColumn = 9;

class Board {
 public:
  Board();
  void LoadStandardBoard();
  void LoadBoard(int* pieces);
  std::shared_ptr<MoveState> MakeMove(std::shared_ptr<Location> location, const Move& move) throw (piece_not_found, std::out_of_range);
  void UnmakeMove(std::shared_ptr<MoveState> move_state) throw (invalid_move, std::out_of_range);
  std::shared_ptr<Piece> GetPiece(std::shared_ptr<Location> location) throw (std::out_of_range);
  void SetPiece(std::shared_ptr<Location> location, std::shared_ptr<Piece> piece) throw (std::out_of_range);
  bool InBounds(std::shared_ptr<Location> location);
  bool InFort(std::shared_ptr<Location> location);
  bool InRedHalf(std::shared_ptr<Location> location);
  bool InBlackHalf(std::shared_ptr<Location> location);
  std::shared_ptr<Location> ToLocation(std::shared_ptr<Piece> piece, std::shared_ptr<Location> from, const Move& move) ;
  int Location2Position(std::shared_ptr<Location> location) const;
  int Location2Position(int row, int column) const;


  int red_forward() {
    return red_forward_;
  }

  int black_forward() {
    return black_forward_;
  }

  int red_left() {
    return red_left_;
  }

  int black_left() {
    return black_left_;
  }

 private:

  void InitDirection(bool upper_half_red);
  
  std::vector<std::shared_ptr<Piece>> board_;
  int red_forward_;
  int black_forward_;
  int red_left_;
  int black_left_;
  int red_half_begin_;
  int red_half_end_;
  int black_half_begin_;
  int black_half_end_;

};


} // namespace chess

#endif