#! /bin/bash
set -e

#Icon
#cp ${PWD}/../../resources/yapg.icns ${1}/Contents/Resources/
#sed 's/<string><\/string>/<string>yapg<\/string>/g' -i ${1}/Contents/Info.plist

${QTDIR}/bin/macdeployqt ${1} -dmg
