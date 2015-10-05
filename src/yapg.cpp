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

#include <QMessageBox>


#include "yapg.h"
#include "Generator.h"

const QVector<QChar> yapg::s_defaultSymbSet = QVector<QChar>() << '&' << '#' << '\'' << '{' << '}' << '(' << ')' << '[' << ']' << '-' << '_' << '|' << '\\' << '/' << '@' << '+' << '=' << '*' << '$' << ',' << ';' << ':' << '!' << '?' << '.' ;

yapg::yapg(void)
    : QMainWindow(),
    _nbCapitals(0), _nbNumbers(0), _nbSymbols(0)
{
  _ui.setupUi(this);
  QString symbSet;
  foreach( QChar c, s_defaultSymbSet ) {
    symbSet.append( c );
  }
  
  _ui.le_SymbolSet->setText( symbSet );
  
  _nbCapitals = _ui.sb_NbCapitals->value();
  _nbNumbers = _ui.sb_NbNumbers->value();
  _nbSymbols = _ui.sb_NbSymbols->value();
  
  //connections to gui
  bool fconnected = static_cast<bool>( connect( _ui.pb_Generate, SIGNAL(clicked()), this, SLOT(onGenerate()) ) );
  fconnected &= static_cast<bool>(connect(_ui.actionAbout, SIGNAL(triggered()), this, SLOT(onAbout())) );
  fconnected &= static_cast<bool>(connect(_ui.sb_NbCapitals, SIGNAL(valueChanged(int)), this, SLOT(onNbCapitals(int))) );
  fconnected &= static_cast<bool>(connect(_ui.sb_NbNumbers, SIGNAL(valueChanged(int)), this, SLOT(onNbNumbers(int))) );
  fconnected &= static_cast<bool>(connect(_ui.sb_NbSymbols, SIGNAL(valueChanged(int)), this, SLOT(onNbSymbols(int))) );
}

yapg::~yapg()
{

}

void yapg::onGenerate( void )
{
  try
  {
      CGenerator::t_Parameters params;
      CGenerator generator;
  
      //reading params
      params.length = _ui.sb_Length->value();
      _ui.cb_Capitals->isChecked() ? params.nbCapitals = _ui.sb_NbCapitals->value() : params.nbCapitals = 0;  
      _ui.cb_Numbers->isChecked() ? params.nbNumbers = _ui.sb_NbNumbers->value() : params.nbNumbers = 0; 
      _ui.cb_Symbols->isChecked() ? params.nbSymbols = _ui.sb_NbSymbols->value() : params.nbSymbols = 0;
      params.nbToGenerate = _ui.sb_NbToGenerate->value();
      QString symbSet = _ui.le_SymbolSet->text();
      for(int i = 0; i < symbSet.length(); i++ ) {
        params.symbolSet << symbSet[i];
      }

      //generation
      QVector<QString> passwords = generator.generate( params );
  
      //display result
      foreach( QString password, passwords ) {
        _ui.te_Result->appendPlainText( password );
      }
  }
  catch( QString exception ) {
      QMessageBox msg( QMessageBox::Critical, tr("An exception occurred"), exception );
      msg.exec();
  }
  
}

void yapg::onAbout( void )
{
    QMessageBox::about( this,
                        tr("About YAPG"),
                        "(c)2013-2015<br/>Yet Another Password Generator by Christophe Meneboeuf dev@ezwebgallery.org.<br/>Software provided under the GNU GPLv3 license." );
}


void yapg::onNbCapitals( int newValue )
{
  if( static_cast<int>(newValue + _nbNumbers + _nbSymbols) >= _ui.sb_Length->value() ) {
    newValue = _ui.sb_Length->value() - _nbNumbers - _nbSymbols;
    _ui.sb_NbCapitals->setValue( newValue );
  }
  _nbCapitals = newValue;
}

void yapg::onNbNumbers( int newValue )
{
  if( static_cast<int>(_nbCapitals + newValue + _nbSymbols) >= _ui.sb_Length->value() ) {
    newValue = _ui.sb_Length->value() - _nbCapitals - _nbSymbols;
    _ui.sb_NbNumbers->setValue( newValue );
  }
  _nbNumbers = newValue;

}

void yapg::onNbSymbols( int newValue )
{
  if( static_cast<int>(_nbCapitals + _nbNumbers + newValue) >= _ui.sb_Length->value() ) {
    newValue = _ui.sb_Length->value() - _nbCapitals - _nbNumbers;
    _ui.sb_NbSymbols->setValue( newValue);
  }
  _nbSymbols = newValue;

}
