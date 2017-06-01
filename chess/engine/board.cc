
//Created on 2017-05-14
//@author: linjiafang33@163.com

//#include "log/log.h"

#include "board.h"
#include "move_state.h"



namespace chess {

static int kBoardStandard[kDroppointNumber] = {
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

static bool kBoardFort[kDroppointNumber] = {
   0,  0,  0,  1,  1,  1,  0,  0,  0,
   0,  0,  0,  1,  1,  1,  0,  0,  0,
   0,  0,  0,  1,  1,  1,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  1,  1,  1,  0,  0,  0,
   0,  0,  0,  1,  1,  1,  0,  0,  0,
   0,  0,  0,  1,  1,  1,  0,  0,  0,
};


Board::Board() : red_forward_(kLineCount),
                 black_forward_(-kLineCount),
                 red_left_(1),
                 black_left_(-1),
                 red_half_begin_(0),
                 red_half_end_(kUpperHalfEnd),
                 black_half_begin_(kUpperHalfEnd+1),
                 black_half_end_(kDroppointNumber-1) {
  board_.reserve(kDroppointNumber);
}

void Board::LoadStandardBoard() {
  LoadBoard(kBoardStandard);
}

void Board::LoadBoard(int* pieces) {
  board_.clear();

  for (int r = 1; r <= kBoardRow; ++r) {
    for (int c = 1; c <= kBoardColumn; ++c) {
      int position = Location2Position(r, c);

      std::shared_ptr<Piece> piece = Piece::CreatePiece(pieces[position]);
      board_.push_back(piece);

      if (piece->piece_type() == chess::Piece::kRedKing) {
        if (position <= kUpperHalfEnd) {
          InitDirection(true);
        } else {
          InitDirection(false);
        }
      }
    }
  }
}

void Board::InitDirection(bool upper_half_red) {
  if (upper_half_red) {
    red_forward_ = 1;
    black_forward_ = -1;
    red_left_ = 1;
    black_left_ = -1;

    red_half_begin_ = 0;
    red_half_end_ = kUpperHalfEnd;
    black_half_begin_ = kUpperHalfEnd + 1;
    black_half_end_ = kDroppointNumber - 1;

  } else {
    red_forward_ = -1;
    black_forward_ = 1;
    red_left_ = -1;
    black_left_ = 1;

    red_half_begin_ = kUpperHalfEnd + 1;
    red_half_end_ = kDroppointNumber - 1;
    black_half_begin_ = 0;
    black_half_end_ = kUpperHalfEnd;
  }
}

std::shared_ptr<Location> Board::ToLocation(std::shared_ptr<Piece> piece, std::shared_ptr<Location> from, const Move& move) {
  int left = red_left();
  int forward = red_forward();
  if (piece->IsBlack()) {
    left = black_left();
    forward = black_forward();
  } 

  int column = from->column() + (move.left_num() * left);
  int row = from->row() + (move.forward_num() * forward);

  return std::shared_ptr<Location>(new Location(row, column));
}

std::shared_ptr<MoveState> Board::MakeMove(std::shared_ptr<Location> location, const Move& move) 
    throw (piece_not_found, std::out_of_range) {
  std::shared_ptr<Piece> from_piece = GetPiece(location);
  if (from_piece->Empty()) {
    throw piece_not_found("piece not found in from-location");
  }

  std::shared_ptr<Location> to_location = ToLocation(from_piece, location, move);
  std::shared_ptr<MoveState> move_state(new MoveState(from_piece, location, to_location, move));
  std::shared_ptr<Piece> to_piece = GetPiece(move_state->to());

  SetPiece(move_state->to(), from_piece);
  SetPiece(move_state->from(), Piece::GetEmptyPiece());

  move_state->SetKilledPiece(to_piece);
  return move_state;
}

void Board::UnmakeMove(std::shared_ptr<MoveState> move_state) 
    throw (invalid_move, std::out_of_range) {
  std::shared_ptr<Piece> to_piece = GetPiece(move_state->to());
  if (to_piece != move_state->moved_piece()) {
    throw invalid_move("move piece not equal to board piece");
  }

  SetPiece(move_state->to(), move_state->killed_piece());
  SetPiece(move_state->from(), to_piece);
}

std::shared_ptr<Piece> Board::GetPiece(std::shared_ptr<Location> location) throw (std::out_of_range){
  if (!InBounds(location)) {
    throw std::out_of_range("get piece location out of range");
  }

  return board_[Location2Position(location)];
}

void Board::SetPiece(std::shared_ptr<Location> location, std::shared_ptr<Piece> piece) throw (std::out_of_range) {
  if (!InBounds(location)) {
  	//logging::log().error("set piece %d out of bounds", location.Description().c_str());
    throw std::out_of_range("set piece location out of range");
  }

  board_[Location2Position(location)] = piece;
}

bool Board::InBounds(std::shared_ptr<Location> location) {
	if (!(1 <= location->row() 
			&& location->row() <= kBoardRow 
			&& 1 <= location->column() 
			&& location->column() <= kBoardColumn)) {
		return false;
	}

  return true;
}

bool Board::InFort(std::shared_ptr<Location> location) {
  if (!InBounds(location)) {
    return false;
  }

  if (!kBoardFort[Location2Position(location)]) {
    return false;
  }

  return true;
}

bool Board::InRedHalf(std::shared_ptr<Location> location) {
	int position = Location2Position(location);
  return red_half_begin_ <= position && position <= red_half_end_;
}

bool Board::InBlackHalf(std::shared_ptr<Location> location) {
	int position = Location2Position(location);
  return black_half_begin_ <= position && position <= black_half_end_;
}

int Board::Location2Position(std::shared_ptr<Location> location) const {
  return (location->row() - 1) * kLineCount + (location->column() - 1);
}

int Board::Location2Position(int row, int column) const {
  return (row - 1) * kLineCount + (column - 1);
}

} // namespace chess