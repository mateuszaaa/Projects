
#include <list>
#include "list.hh"

/**
* @brief  destroys the object
*/
CommandsList::~CommandsList()
{
    Clear();
}

/**
* @brief adds object to list
*
* @param cmd command to add
*/
void CommandsList::Add2List(Command *cmd)
{
   push_back(cmd);
}

/**
* @brief clears the list
*/
void CommandsList::Clear()
{ 
  list<Command*>::iterator it; 
  it=end();
  while(it!=begin()) {
      it--;
      delete (*it);
      pop_back();
      it=end();
  }
}


