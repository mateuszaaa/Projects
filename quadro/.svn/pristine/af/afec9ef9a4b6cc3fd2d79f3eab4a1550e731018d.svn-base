#ifndef MENU_HH
#define MENU_HH
#include <iostream>
#include "parser.hh"
#include "command.hh"
#include "robotpose.hh"
#include "lacze_do_gnuplota.hh"

/**
* @brief menu class used to createinterface between user and application
*/
class Menu{
public :
    Menu(CommandsParser &,CommandsList &,RobotPose &); 
    void menu();
private:
    
    /**
    * @brief parser
    */
    CommandsParser _parser;
    /**
    * @brief commands list
    */
    CommandsList _list;
    /**
    * @brief robot position
    */
    RobotPose _robot;
    /**
    * @brief input file name
    */
    std::string _input_file_name;
    /**
    * @brief output file name
    */
    std::string _output_file_name;

/**
* @brief choose decision
*
* @param option
*
* @return 1 if everything is ok 
*/
    bool decision(char); 

/**
* @brief  reads commands from file_name defined in class filed
*/
    void readCommands(); 
/**
* @brief shows commands
*/
    void showCommands(); 
/**
* @brief exec commands
*/
    void execCommands(); 
/**
* @brief sets input file
*
* @param file_name
*/
    void setInputFile(std::string); 
/**
* @brief sets output file
*
* @param file_name
*/
    void setOutputFile(std::string); 
/**
* @brief shows help
*/
    void help(); 
};
#endif
