QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-num_lib-Desktop_Qt_6_2_1_MinGW_64_bit-Debug/release/ -lnum_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-num_lib-Desktop_Qt_6_2_1_MinGW_64_bit-Debug/debug/ -lnum_lib
else:unix: LIBS += -L$$PWD/../build-num_lib-Desktop_Qt_6_2_1_MinGW_64_bit-Debug/ -lnum_lib

INCLUDEPATH += $$PWD/../num_lib
DEPENDPATH += $$PWD/../num_lib
