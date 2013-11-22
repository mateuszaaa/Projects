
#ifndef  COMMAND4ROTATE_HH
#define  COMMAND4ROTATE_HH


#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include <cassert>
#include "command.hh"
#include "exception.hh"
class Command4Grasper: public Command {
  bool  _angle_speed;

 public:
  Command4Rotate();  
  void printCmd() const;
  int ExecCmd( RobotPose &pRobPose, std::ostream &Strm_Out) const;
  static Command* CreateCmd();
  static const char* GetCmdName() { return "Rotate"; }
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  void PrintSyntax() const;
 };

#endif
