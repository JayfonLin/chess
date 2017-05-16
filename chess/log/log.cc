
//Created on 2017-05-14
//@author: linjiafang33@163.com

#include "log.h"
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

namespace logging {


Log& Log::GetInstance() {
  static Log log;
  return log;
}

log4cpp::Category& Log::root() {
  static log4cpp::Category& root = log4cpp::Category::getRoot();
  return root;
}

log4cpp::Category& Log::information() {
  static log4cpp::Category& information = log4cpp::Category::getInstance(std::string("information"));
  return information;
}

log4cpp::Category& Log::error() {
  static log4cpp::Category& error = log4cpp::Category::getInstance(std::string("error"));
  return error;
}


Log::Log() {
  std::string init_file_name = "format.properties";
  log4cpp::PropertyConfigurator::configure(init_file_name);

}

log4cpp::Category& log() {
  return Log::GetInstance().information();
}

}


int main() {
  logging::log().info("IN MAIN!");
  logging::log().warn("root in main");

  logging::Log::GetInstance().error().info("error");
  return 0;
}