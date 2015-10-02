
CONFIG  += debug_and_release \

QT += widgets

#### Preprocessor ###
win32:DEFINES += _CRT_RAND_S

### User defined variables ###
Debug|Release{
    BUILDDIR = $$PWD/Linux
}


### Output ###
Debug {
    DESTDIR =        $$BUILDDIR/Debug
    OBJECTS_DIR =    $$BUILDDIR
    MOC_DIR =        $$BUILDDIR
    RCC_DIR =        $$BUILDDIR
    UI_DIR =         $$BUILDDIR
}
Release {
    DESTDIR =      $$BUILDDIR/Release
    OBJECTS_DIR =  $$BUILDDIR
    MOC_DIR =      $$BUILDDIR
    RCC_DIR =      $$BUILDDIR
    UI_DIR =       $$BUILDDIR
}


UI_DIR = $${PWD}/src

INCLUDEPATH +=  $${PWD}/src \
                $${PWD}/src/GeneratedFiles

HEADERS += ./src/Generator.h \
                      ./src/yapg.h \
                      ./src/Seeder.h

SOURCES += ./src/Generator.cpp \
           ./src/yapg.cpp \
           ./src/main.cpp \
           ./src/Seeder.cpp

FORMS += src/yapg.ui


RESOURCES = ./resources/yapg.qrc

### DEPLOYMENT
unix {
        binfile.files += $$DESTDIR/$$TARGET
        binfile.path = /usr/bin/
        icon.path = /usr/share/$$TARGET
        icon.files = $$PWD/resources/system-password-2.png
        desktop.path = /usr/share/applications/
        desktop.files = $$PWD/deployment/linux/yapg.desktop
        INSTALLS += binfile
        INSTALLS += icon
        INSTALLS += desktop
}



### CLEAN
QMAKE_CLEAN += -r $$BUILDDIR

QMAKE_DISTCLEAN += -r   $$BUILDDIR/ \
                   -r   $$PWD/src/GeneratedFiles/ \
                   -r   $$PWD/src/ipch/ \
                        $$PWD/Makefile* \
                        $$PWD/*.pro.*
                   

