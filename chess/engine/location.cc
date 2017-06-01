
//Created on 2017-05-30
//@author: linjiafang33@163.com

#include <cstdio>

#include "location.h"

namespace chess {
Location::Location(int r, int c) : row_(r), column_(c) { }

std::string Location::Description() const {
  char buffer[50];
  snprintf(buffer, sizeof(buffer), "location: (row %d, column %d)", row(), column());
  return std::string(buffer);
}

} // namespace chess