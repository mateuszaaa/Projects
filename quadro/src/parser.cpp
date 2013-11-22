#include "parser.hh"

bool CommandsParser::ReadCmd(LibInterface *interface, istream &IStrm, CommandsList &cmds_list)
{
    if (interface != NULL){
        Command *pCmd = interface->CreateCmd();
        try{
            pCmd->ReadParams(IStrm);
            cmds_list.Add2List(pCmd);
        }catch(std::exception &exc){
            cmds_list.Clear();
            delete pCmd;
            throw;
        }
      return true;
    }else {
        std::cout<<"empty interface is provided"<<std::endl;
        return false;
    }
}


/**
* @brief reads commands list from stream
*
* @param IStrm input string with commands 
* @param cmds_list commands list
*
* @return 
*/
bool CommandsParser::ReadCmdsList( ifstream &IStrm, CommandsList &cmds_list)
{
    int line_nr = 0;
    string cmd_name;
    LibInterface *interface;

    while (IStrm >> cmd_name) {
        line_nr++;
        try{
            if ( cmd_name == "Fly" || cmd_name == "Rotate" || cmd_name == "Gasshoper") {
                interface = _libs_set[std::string(cmd_name)];
            }
            
            if ( interface == NULL ){
                std::cout<<"ERROR : command : >>> "<<cmd_name;
                std::cout<<" <<< not found, try load a proper plugin"<<std::endl;    
                return false;
            }else {
                ReadCmd(interface,IStrm,cmds_list);
            }

        }catch(std::exception &exc){
            cout<<exc.what()<<"at line : "<<line_nr<<endl; 
            break;
        }
    }

    return true;
}

  /**
  * @brief executes  commands list
  *
  * @param file output stream where robot params will be written
  * @param robot robot object
  * @param cmds_list list of commands
  */
  void CommandsParser::execCmdsList(ofstream & file,RobotPose &robot,CommandsList &cmds_list){
     list<Command*>::iterator it; 
     it=cmds_list.begin();
    while (it != cmds_list.end()) {
        (*it)->ExecCmd(robot,file);
        it++;
    }
  }

  /**
  * @brief show commands list
  *
  * @param cmds_list list of commands
  */
  void CommandsParser::showCmdsList(CommandsList &cmds_list){
      list<Command*>::iterator it; 
      it=cmds_list.begin();
      while(it!=cmds_list.end()) {
          (*it)->printCmd();
          it++;
      }
  }

bool CommandsParser::loadLib(const char* lib_name){
    if ( _libs_set.find(lib_name)  != _libs_set.end() ){
        std::cout<<"library already loaded"<<std::endl;
        return false;
    }

    if (! _libs_set.AddLib(lib_name)){
        return false;    
    }

    return true;
}

bool CommandsParser::unloadLib(const char* lib_name){
    LibInterface *interface;
    std::map<std::string,LibInterface*>::iterator it;

    it = _libs_set.find("Rotate");
    interface = it->second;
    _libs_set.erase(it);
    delete interface;
    return true;
}


