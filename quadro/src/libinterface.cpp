#include "libinterface.hh"

using std::string;
using std::cerr;
using std::endl;

LibInterface::LibInterface(): _lib_handler(NULL), _getCmdName(NULL), _createCommand(NULL) {};

LibInterface::~LibInterface() { 
    if (_lib_handler){ 
        Detach();
        dlclose(_lib_handler); 
    }
}


void LibInterface::Detach() 
{ 
    _lib_handler = NULL; 
    _createCommand = NULL;
    _getCmdName = NULL;
}

bool LibInterface::Init4Lib(const char* sLibName){
  _lib_handler = dlopen(sLibName,RTLD_LAZY);
  void *function_ptr;

  if (!_lib_handler) {
    cerr << "!!! Brak biblioteki: "<<sLibName << endl;
    return 1;
  }


  function_ptr = dlsym(_lib_handler,"CreateCmd");
  if (!function_ptr) {
    cerr << dlerror() << endl;
    return 1;
  }
  _createCommand = *reinterpret_cast<Command* (**)(void)>(&function_ptr);



  function_ptr = dlsym(_lib_handler,"GetCmdName"); 
  if (!_lib_handler) {
    cerr << dlerror() << endl;
    return 1;
  }
  _getCmdName = *reinterpret_cast<const char* (**)()>(&function_ptr);

return 0;
}


