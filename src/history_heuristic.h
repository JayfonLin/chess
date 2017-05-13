
//Created on 2017-05-07
//@author: linjiafang33@163.com


#ifndef CHESS_SRC_HISTORY_HEURISTIC_H
#define CHESS_SRC_HISTORY_HEURISTIC_H

namespace chess {
struct Move; 

class HistoryHeuristic {
 public:
  const static int kHistoryMoveSize = 1 << 16;

  void ResetHistoryTable();
  int GetHistoryScore(Move move);
  void EnterHistoryScore(Move move, int depth);
  void MergeSort(Move source[], int n, bool direction);

 private:
  void Merge(Move source[], Move target[], int l, int m, int r);
  void MergePass(Move source[], Move target[], int s, int n, bool direction);
  void MergeA(Move source[], Move target[], int l, int m, int r);

  int history_table_[kHistoryMoveSize];
  Move target_buff_[100];
   
};
}

#endif