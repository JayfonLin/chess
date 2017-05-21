
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "exceptions.h"


namespace chess {

piece_not_found::piece_not_found(const std::string &s) : std::logic_error(s) { }
piece_not_found::~piece_not_found() throw() { }

invalid_move::invalid_move(const std::string &s) : std::logic_error(s) { }
}