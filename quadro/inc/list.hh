#ifndef LIST_HH
#define LIST_HH
#include "command.hh"
#include <boost/foreach.hpp>
#include <list> 
#include <iostream>
using namespace std;
/*!
 * \brief class used to store commands list
 */
class CommandsList: public std::list<Command*> {
  public:

/**
* @brief adds object to list
*
* @param cmd command to add
*/
   void Add2List(Command *pCmd);
/**
* @brief clears the list
*/
   void Clear();

/**
* @brief  destroys the object
*/
   ~CommandsList();
};
#endif
