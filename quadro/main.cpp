

#include <iostream>
#include <fstream>
#include <string>
#include "parser.hh"
#include "exception.hh"
#include "list.hh"
#include "lacze_do_gnuplota.hh"
#include "menu.hh"

using namespace std;


 int main()
 {
    CommandsList list;
    CommandsParser parser;
    RobotPose robot;

    if (! parser.loadLib("Rotate") ) {
       std::cout<<"loding Rotate failed"<<std::endl; 
    }
    if (! parser.loadLib("Fly") ) {
       std::cout<<"loding Fly failed"<<std::endl; 
    }

    Menu menu(parser,list,robot);
#ifdef FAST
    menu.setInputFile("c");
    menu.readCommands();
    menu.execCommands();
#else
   menu.menu();
#endif
 }
