#include "command4rotate.hh"

using std::cout;
using std::endl;


extern "C"{
    const char* GetCmdName(void);
    void PrintSyntax(void);
    Command* CreateCmd(void);
}


const char* GetCmdName(void) {
    return Command4Rotate::GetCmdName();
} 

void PrintSyntax(void)
{
    std::cout<<Command4Rotate::GetCmdName()<<" params "<<std::endl;
}

Command* CreateCmd()
{
 return Command4Rotate::CreateCmd();
}




/**
* @brief initialize objects fileds with 0 value
*/
Command4Rotate::Command4Rotate(): _angle_speed(0), _angle(0)
{}








/**
* @brief Prints command using actual fields values
*/
void Command4Rotate::printCmd() const
{
  cout << GetCmdName() << " " << 
  _angle_speed  << " " << 
  _angle  << " ;" <<endl;
}


/**
* @brief Runs commands which makes robot move 
*
* @param robot objects to rotate
* @param out file to save robot position
*
* @return 
*/
int Command4Rotate::ExecCmd(RobotPose &robot, std::ostream& Strm_Out) const
{
    double time = 0.01;
    double actual_angle = 0;
    double step_angle = 0;
    

    while (actual_angle <=_angle){
            step_angle = time *_angle_speed;
            actual_angle += step_angle;
            robot.alpha_deg += step_angle;
        }
return 0;
}


/**
* @brief Reeds params from string
*
* @param stream input stream with data
*
* @return return True if everything went ok
*/
bool Command4Rotate::ReadParams(std::istream& stream)
{
    char comma;
    double angle_speed;
    double angle;

    stream>>angle_speed;
    stream>>comma;

    if (comma != ','){
        throw CommandParamsError();        
    }

    stream>>angle;
    if (angle < 0){
        throw CommandParamsError();        
    }

    stream>>comma;
    if (comma != ';'){
        throw CommandParamsError();        
    }

    _angle_speed = angle_speed;
    _angle = angle;    
  return true;
}


/** * @brief returns objects instance 
*
* @return returns objects instance 
*/
Command* Command4Rotate::CreateCmd()
{
  return new Command4Rotate();
}


/**
* @brief Prints command syntax 
*/
void Command4Rotate::PrintSyntax()  const
{
  cout << "   Rotate  angle_speed[degrees/s], angle[degrees];" << endl;
}
