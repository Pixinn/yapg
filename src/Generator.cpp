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

#include "Rand.h"
#include "Generator.h"

const QVector<QChar> CGenerator::s_charSet = QVector<QChar>() <<'a'<<'b'<<'c'<<'d'<<'e'<<'f'<<'g'<<'h'<<'i'<<'j'<<'k'<<'l'<<'m'<<'n'<<'o'<<'p'<<'q'<<'r'<<'s'<<'t'<<'u'<<'v'<<'w'<<'x'<<'y'<<'z';
const QVector<QChar> CGenerator::s_capitalSet = QVector<QChar>() <<'A'<<'B'<<'C'<<'D'<<'E'<<'F'<<'G'<<'H'<<'I'<<'J'<<'K'<<'L'<<'M'<<'N'<<'O'<<'P'<<'Q'<<'R'<<'S'<<'T'<<'U'<<'V'<<'W'<<'X'<<'Y'<<'Z';
const QVector<QChar> CGenerator::s_numberSet = QVector<QChar>() <<'0'<<'1'<<'2'<<'3'<<'4'<<'5'<<'6'<<'7'<<'8'<<'9';



QVector<QString> CGenerator::generate( const t_Parameters& params )
{
  QVector<QString> passwords;

  QVector<QChar> charSet;
  charSet += s_charSet;
  if( params.nbCapitals > 0 ) { charSet += s_capitalSet; }
  if( params.nbNumbers > 0 ) { charSet += s_numberSet; }
  if( params.nbSymbols > 0 ) { charSet += params.symbolSet; }

  for( unsigned int i = 0; i < params.nbToGenerate; i++ )
  {
      QList<QChar> rdmSet;
      rdmSet << getRdmChars( s_capitalSet, params.nbCapitals );
      rdmSet << getRdmChars( s_numberSet, params.nbNumbers );
      rdmSet << getRdmChars( params.symbolSet, params.nbSymbols );
      rdmSet << getRdmChars( charSet, params.length - params.nbCapitals - params.nbNumbers - params.nbSymbols );
      passwords << getRmdPassword( rdmSet );
  }

  return passwords;
}


QList<QChar> CGenerator::getRdmChars( const QVector<QChar>& charSet, const unsigned int nb) const
{
  QList<QChar> rdmChars;
  for( unsigned int j = 0; j < nb; j ++ )  {
    int index = _rnd.execute() % charSet.size();
    rdmChars << charSet.at(index);
  }
  return rdmChars;
}

QString CGenerator::getRmdPassword( QList<QChar> charSet ) const
{
  QString password;
  while( charSet.size() > 0 ) {
    int index = _rnd.execute() % charSet.size();
    password.append( charSet.takeAt(index) );
  }
  return password;
}

