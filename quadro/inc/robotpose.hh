#ifndef  ROBOTPOSE_HH
#define  ROBOTPOSE_HH


#include <iostream>
#include "robotpose.hh"

/*!
 * \file
 * \brief Definicja klasy RobotPose
 *
 * Plik zawiera definicję klasy RobotPose
 */

/*!
 * \brief class used to stroe info about robot position
 *
 */
struct RobotPose {
  double   x_m, y_m, z_m, alpha_deg;
};




#endif
