
//Created on 2017-05-14
//@author: linjiafang33@163.com

#ifndef CHESS_LOG_LOG_H
#define CHESS_LOG_LOG_H

#include <log4cpp/Category.hh>

namespace logging{
class Log {
public:
  static Log& GetInstance();
  
  log4cpp::Category& information();
  log4cpp::Category& root();
  log4cpp::Category& error();

private:
  Log();
  Log(const Log&);
  Log& operator=(const Log&);

};

log4cpp::Category& log();
}



#endif