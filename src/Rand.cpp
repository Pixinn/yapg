/* 
 *  YAPG:
 *  Copyright (C) 2014 Christophe Meneboeuf <dev@ezwebgallery.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <QObject>
#include <QtGlobal>
#include <QString>

#include "Rand.h"

Rand Rand::s_instance;


#ifdef Q_OS_WIN32
#include <cstdlib>
#include <cassert>
unsigned int Rand::execute(void) const
{
    unsigned int rnd;
    if (rand_s(&rnd) != 0) { //rand_s returns 0 if OK
      throw _exceptionStr;
    }
    return rnd;
}
#endif


#if defined(Q_OS_LINUX) || defined(Q_OS_MAC)
#include <cstdio> 
unsigned int Rand::execute( void ) const
{
  FILE *urandom;
  unsigned int rnd;
  urandom = fopen ("/dev/urandom", "r");
  if( fread( &rnd, sizeof(rnd), 1, urandom ) != 1 ) {
    throw _exceptionStr;
  }
  return rnd;
}
#endif
