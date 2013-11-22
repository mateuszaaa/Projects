#ifndef  COMMAND4FLY_HH
#define  COMMAND4FLY_HH


#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include <cmath>
#include <unistd.h>
#include <cassert>
#include "command.hh"
#include "exception.hh"

class Command4Fly: public Command {
  double  _speed_horizontal;
  double  _speed_vertical;
  double  _length;

 public:
  Command4Fly();  
  void printCmd() const;
  int ExecCmd( RobotPose &pRobPose, std::ostream   &Strm_Out) const;
  static Command* CreateCmd();
  static const char* GetCmdName() { return "Fly"; }
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  void PrintSyntax() const;
 };

#endif
