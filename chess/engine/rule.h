
//Created on 2017-05-25
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_RULE_H
#define CHESS_ENGINE_RULE_H

#include <memory>

#include "board.h"
#include "move.h"
#include "move_state.h"
#include "piece.h"

namespace chess {
namespace rule {

bool ValidMove(std::shared_ptr<Board> board, std::shared_ptr<Location> location, const Move& move);
bool SameParty(std::shared_ptr<Piece> piece_a, std::shared_ptr<Piece> piece_b);
bool ValidMoveState(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
int PieceNumBetweenLine(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsRookMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsKingMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsHorseMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsBishopMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsBodyGuardMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsCannonMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool IsPawnMoveValid(std::shared_ptr<Board> board, std::shared_ptr<MoveState> move_state);
bool HasCrossedRiver(std::shared_ptr<Board> board, std::shared_ptr<Piece> piece, std::shared_ptr<Location> location);

} // namespace rule
} // namespce chess

#endif