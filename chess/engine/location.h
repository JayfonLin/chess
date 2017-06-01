
//Created on 2017-05-30
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_LOCATION_H
#define CHESS_ENGINE_LOCATION_H

#include <string>

namespace chess {
class Location {
 public:
  Location(int r, int c);
  
  int row() const {
    return row_;
  }

  int column() const {
    return column_;
  }

  std::string Description() const;

 private:
  int row_;
  int column_;

};

} // namespace chess

#endif