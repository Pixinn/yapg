/* 
 *  YAPG:
 *  Copyright (C) 2014-2015 Christophe Meneboeuf <dev@ezwebgallery.org>
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

#ifndef _RAND_H
#define _RAND_H

#include <QObject>
#include <QString>

//Generate a SECURE seed
//Platform specific implementations of execute()
class Rand
{
public:

	Rand(void) :
     _exceptionStr( QObject::tr("Impossiblility to get random material.") )
    {  }
	~Rand(void) {}

  static Rand& GetInstance(void) {
    return s_instance;
  }

  unsigned int execute( void ) const;

private:
  static Rand s_instance;
  const QString _exceptionStr;
};

#endif
