#ifndef  COMMAND_HH
#define  COMMAND_HH

/*+- SVN Keywords ----------------------------------------------------+
 *|                                                                   |
 *| $HeadURL:: svn+ssh://diablo/home/mnowakow/ZMP/QUADRO/branches/s#$:|
 *|     $Rev:: 21                                                   $:|
 *|    $Date:: 2013-11-13 18:21:57 +0100 (śro)                     $:|
 *|  $Author:: mnowakow                                             $:|
 *|                                                                   |
 *+-------------------------------------------------------------------+
 */

#include <iostream>
#include "robotpose.hh"

/*!
 * \file
 * \brief Definicja klasy Command
 *
 * Plik zawiera definicję klasy Command ...
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
 class Command {
  public:
   /*!
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    *  
    */
   virtual ~Command() {}
   /*!
    * \brief
    */
   virtual void printCmd() const = 0;
   virtual int ExecCmd(   RobotPose       &RobPose, 
                          std::ostream    &Strm_Out
                      ) const = 0;
   /*!
    * \brief
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
 };

#endif
