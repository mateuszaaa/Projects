#ifndef PARSER_HH
#define PARSER_HH
#include <iostream>
#include <fstream>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>
#include "command.hh"
#include "list.hh"
#include "libinterface.hh"
#include "set4libinterfaces.hh"
using namespace std;
/**
* @brief class used to parse commands
*/
class CommandsParser {
  public:

  /**
  * @brief used to read commands from provided
  * stream and adds them to provided commands list
  *
  * @param file stream 
  * @param commands list
  *
  * @return true if there were no errors
  */
  bool ReadCmdsList( ifstream &, CommandsList &);
  /**
  * @brief read fly command
  * reads data from input file string and if they have correct syntax 
  * adds them to command list
  *
  * @param input file stream
  * @param command list
  *
  * @return true if there were no errors
  */
  bool ReadCmd(LibInterface *, istream &, CommandsList &);
  /**
  * @brief read rotate command
  * reads data from input file string and if they have correct syntax 
  * adds them to command list
  *
  * @param input file stream
  * @param command list
  *
  * @return true if there were no errors
  */
  void showCmdsList(CommandsList &);
  /**
  * @brief executes commands from list and updates robot position
  * every 0.01s it saves robot position to output stream
  *
  * @param  output stream
  * @param  robot position
  * @param  commands list
  */
  void execCmdsList(ofstream & ,RobotPose&,CommandsList &);
  bool loadLib(const char* lib_name);
  bool unloadLib(const char* lib_name);

  private:
  Set4LibInterfaces _libs_set;
};

#endif
