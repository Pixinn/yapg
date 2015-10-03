/* 
 *  YAPG:
 *  Copyright (C) 2013-2015 Christophe Meneboeuf <dev@ezwebgallery.org>
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

#ifndef YAPG_H
#define YAPG_H

#include <QMainWindow>

#include "ui_yapg.h"

class yapg : public QMainWindow
{
    Q_OBJECT

public:
    yapg(void);
    ~yapg();

public slots:
  void onGenerate( void );
  void onAbout( void );
  void onNbCapitals( int );
  void onNbNumbers( int );
  void onNbSymbols( int );

private:
  static const QVector<QChar> s_defaultSymbSet;    
  Ui::yapgClass _ui;
  unsigned int _nbCapitals;
  unsigned int _nbNumbers;
  unsigned int _nbSymbols;
    
};

#endif // YAPG_H
