QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-score-Desktop_Qt_6_2_1_MinGW_64_bit-Release/release/ -lscore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-score-Desktop_Qt_6_2_1_MinGW_64_bit-Release/debug/ -lscore
else:unix: LIBS += -L$$PWD/../build-score-Desktop_Qt_5_12_9_MinGW_64_bit-Release/ -lscore

INCLUDEPATH += $$PWD/../score
DEPENDPATH += $$PWD/../score


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-about-Desktop_Qt_6_2_1_MinGW_64_bit-Release/release/ -labout
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-about-Desktop_Qt_6_2_1_MinGW_64_bit-Release/debug/ -labout
else:unix: LIBS += -L$$PWD/../build-about-Desktop_Qt_5_12_9_MinGW_64_bit-Release/ -labout

INCLUDEPATH += $$PWD/../about
DEPENDPATH += $$PWD/../about
