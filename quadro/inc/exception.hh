#ifndef EXCEPTIONS_HH
#define EXCEPTIONS_HH
#include <exception>
#include <iostream>
/**
* @brief class used to throw excepion when file is not open
*/
class FileOpenProblem: public std::exception{
    virtual const char* what() const throw()
      {
        return "File open problem";
      }
};

/**
* @brief class used to throw excepion when file is not open
*/
class CommandParamsError: public std::exception{
    virtual const char* what() const throw()
      {
          std::string error = "Wrong commands file format line ";
          return error.c_str(); 
      }
};

class WrongLibraryName: public std::exception{
    virtual const char* what() const throw()
      {
          std::string error = "Wrong library bane";
          return error.c_str(); 
      }
};

#endif
