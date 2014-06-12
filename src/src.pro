SOURCES += ndsromorg.cpp \
           main.cpp \
 cndsrosettingsdlg.cpp \
 NDSROconfig.cpp \
 cndsromaindlg.cpp \
 NDSromData.cpp \
 NDSromScanner.cpp \
 NDSdbIfc.cpp \
 NDSbgr555.cpp \
 cndsrodetaildlg.cpp \
 QClickableLabel.cpp \
 NDSromCRC32.cpp \
 NDStransfer.cpp \
 lz4.cpp
HEADERS += ndsromorg.h \
 cndsrosettingsdlg.h \
 NDSROconfig.h \
 cndsromaindlg.h \
 NDSromData.h \
 NDSromScanner.h \
 NDSrominfo.h \
 NDSromCRC32.h \
 NDSrommaker.h \
 NDSdbIfc.h \
 NDSdebug.h \
 NDSbgr555.h \
 cndsrodetaildlg.h \
 QClickableLabel.h \
 NDStransfer.h \
 lz4.h \
 NDSROversion.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ndsromorg
DESTDIR = ../bin
RESOURCES = application.qrc
FORMS += NDSROmainDlg.ui \
NDSROsettingsDlg.ui \
NDSROdetailDlg.ui
QT += sql \
      network
