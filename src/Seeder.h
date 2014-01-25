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

#ifndef _SEEDER_H_
#define _SEEDER_H_


//Generate a SECURE seed
//Platform specific implementations of execute()
class Seeder
{
public:

  Seeder(void){  }
  ~Seeder(void) {}

  static Seeder& GetInstance( void ) { 
    return s_instance;
  }

  unsigned int execute( void );

private:
  static Seeder s_instance;
};

#endif
