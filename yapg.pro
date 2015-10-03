
CONFIG  += debug_and_release \

QT += widgets

#### Preprocessor ###
win32:DEFINES += _CRT_RAND_S

### User defined variables ###
unix {
	OS = Unix
}
win32 {
	OS = Win32
}
Debug|Release{
    BUILDDIR = $$PWD/$$OS
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
                      ./src/Rand.h

SOURCES += ./src/Generator.cpp \
           ./src/yapg.cpp \
           ./src/main.cpp \
           ./src/Rand.cpp

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
                   

