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

#ifndef GENERATOR_H
#define GENERATOR_H

#include <QVector>
#include <QList>
#include <QChar>
#include <QString>

class CGenerator
{
public:

  typedef struct {
    unsigned int length;
    unsigned int nbCapitals;
    unsigned int nbNumbers;
    unsigned int nbSymbols;
    unsigned int nbToGenerate;
    QVector<QChar> symbolSet;
  }t_Parameters;

  CGenerator(void);
  ~CGenerator(void);

  QVector<QString> generate( const t_Parameters& );

private:

  QList<QChar> getRdmChars( const QVector<QChar>&, const unsigned int) const;
  QString getRmdPassword( QList<QChar> ) const;

  static const QVector<QChar> s_charSet;
  static const QVector<QChar> s_capitalSet;
  static const QVector<QChar> s_numberSet;
};

#endif

