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

#include "Seeder.h"

Seeder Seeder::s_instance;


#ifdef Q_OS_WIN32
#include <cstdlib>
#include <cassert>
unsigned int Seeder::execute( void )
{
  unsigned int seed;
  if( rand_s( &seed ) != 0 ) { //rand_s returns 0 if OK
      throw _exceptionStr;
  }
  return seed;
}
#endif


#ifdef Q_OS_LINUX
#include <cstdio> 
unsigned int Seeder::execute( void )
{
  FILE *urandom;
  unsigned int seed;
  
  urandom = fopen ("/dev/urandom", "r");
  if( fread( &seed, sizeof(seed), 1, urandom ) != 1 ) {
    throw _exceptionStr;
  }

  return seed;
}
#endif
