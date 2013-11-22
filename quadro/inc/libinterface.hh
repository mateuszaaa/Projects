#ifndef LIBINTERFACE_HH
#define LIBINTERFACE_HH

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "command.hh"

/*!
 * \file
 * 
 * \brief Zawiera definicję klasy LibInterface
 *
 *  Plik zawiera definicję klasy LibInterface, która modeluje
 *  interfejs biblioteki zawierającej implementację polecenia
 *  dla manipulatora.
 */

/*!
 * \brief Klasa modeluje interfejs wtyczki 
 * 
 * Klasa modeluje listę interfejs biblioteki dynamicznie konsolidowanej,
 * która stanowi wtyczkę dla programu głównego, który umożliwia
 * egzekujcję poleceń. Wspomniana wtyczkę zawiera implementację
 * nowego polecenia.
 */
class LibInterface {
  public:
    LibInterface();
    ~LibInterface() ;
    bool Init4Lib(const char* sLibName);
    void Detach() ;

    const char * GetCmdName(){
        return _getCmdName();
    }

    Command * CreateCmd(){
        return _createCommand();
    }

  private:
   /*!
    * \brief Uchwyt do biblioteki dynamicznie konsolidowanej
    *
    *  Pole zawiera wskaźnik będący uchwytem do załadowanej
    *  biblioteki dynamicznie konsolidowanej.
    *  Wszystkie pozostałe pola tej klasy muszą zawierać wskaźniki
    *  do funkcji z tej właśnie biblioteki.
    */
    void  *_lib_handler; 
   /*!
    * \brief Wskaźnik na funkcję zwracającą nazwę polecenia
    *
    *  Wskaźnik na funkcję zwracającą nazwę polecenia,
    *  które zdefiniowane jest w danej bibliotece.
    */   
    const char* (*_getCmdName)(void);
    Command  *(*_createCommand)(void);

  /*
   *  Podobnie nalezy definiowac inne polecenia i nazwy
   */
};


#endif
