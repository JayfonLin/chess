
//Created on 2017-05-14
//@author: linjiafang33@163.com

#ifndef CHESS_ENGINE_EXCEPTIONS_H
#define CHESS_ENGINE_EXCEPTIONS_H

#include <string>
#include <stdexcept>

namespace chess {
class piece_not_found: public std::logic_error{
public:
  piece_not_found(const std::string &s);
  ~piece_not_found() throw();
};
}

#endif

