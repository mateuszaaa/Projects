#include "set4libinterfaces.hh"

using namespace std;



/*!
 *
 */
Set4LibInterfaces::~Set4LibInterfaces()
{
  /*
   *  Tutaj trzeba wpisac odpowiedni kod
   */
}



/*!
 * \brief Dodaje nowa biblioteke
 *
 * Dodaje nowa bibliotekę, która zawiera implementację nowego 
 * polecenia.
 * \param[in] sLibName - nazwa pliku z biblioteką, która ma zostać
 *                       załadowana i dodana do zbioru bibliotek zawierających
 *                       implementację poszczególnych poleceń.
 * \retval true - operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool Set4LibInterfaces::AddLib(const char*  lib_name)
{
    LibInterface *interface = NULL;

    if (std::string(lib_name) == "Rotate"){
       interface = new LibInterface();
       interface->Init4Lib("./lib/libcommand4rotate.a");
    }

    if (std::string(lib_name) == "Fly"){
       interface = new LibInterface();
       interface->Init4Lib("./lib/libcommand4fly.a");
    }
    
    if (std::string(lib_name) == "Grasshop"){
       interface = new LibInterface();
       interface->Init4Lib("./lib/libcommandgrasshopper.a");
    }

    if (interface == NULL){
        return false;
    }else {
        insert(pair<string,LibInterface*>( std::string(lib_name),interface) );
        return true;
    }

}



/*!
 * Szuka obiektu pełniącego rolę interfejsu biblioteki, który 
 * odpowiada poleceniu o podanej nazwie np. Move.
 *
 * \param sCmdName - nazwa polecenia, dla którego szukany jest
 *                   interfejs do biblioteki zawierającej 
 *                   implementację danego polecenia.
 * \return Jeśli obiekt reprezentujący interfejs biblioteki 
 *         danego polecenia zostanie znaleziony, to zwracany
 *         jest jego adres. W przypadku przeciwnym zwracany
 *         jest adres \p NULL.
 */
const LibInterface* Set4LibInterfaces::FindLib4Cmd(const char*  sCmdName) const
{
  map<string,LibInterface*>::const_iterator  Iter = 
                                       map<string,LibInterface*>::find(sCmdName);

  if (Iter == end()) return NULL;
  return Iter->second;
}

