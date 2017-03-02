#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T10:22:20
#
#-------------------------------------------------

QT       += core gui

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Goto
TEMPLATE = app


SOURCES  += \
        src/Character.cpp \
        src/item.cpp \
        src/Timezone.cpp \
        src/GoToTime.cpp \
        src/output.cpp \
        src/mainwindow.cpp \
        src/tzportal.cpp \
        src/tz20.cpp \
        src/tz30.cpp \
        src/tz40.cpp \
        src/tz50.cpp \
        src/tz60.cpp \
        src/tz70.cpp \
        src/tz80.cpp \
        src/tz90.cpp \
        src/tz00.cpp \
        src/tzpresent.cpp \
        src/tz00widget.cpp \
        src/tz20widget.cpp \
        src/tz30widget.cpp \
        src/tz40widget.cpp \
        src/tz50widget.cpp \
        src/tz60widget.cpp \
        src/tz70widget.cpp \
        src/tz80widget.cpp \
        src/tz90widget.cpp \
        src/tzPresentwidget.cpp


HEADERS  += \
        include/Character.h \
        include/item.h \
        include/Timezone.h \
        include/GoToTime.h \
        include/output.h \
        include/mainwindow.h \
        include/tzportal.h \
        include/tz20.h \
        include/tz30.h \
        include/tz40.h \
        include/tz50.h \
        include/tz60.h \
        include/tz70.h \
        include/tz80.h \
        include/tz90.h \
        include/tz00.h \
        include/tzpresent.h \
        include/tz00widget.h \
        include/tz20widget.h \
        include/tz30widget.h \
        include/tz40widget.h \
        include/tz50widget.h \
        include/tz60widget.h \
        include/tz70widget.h \
        include/tz80widget.h \
        include/tz90widget.h \
        include/tzPresentWidget.h

FORMS += \
    forms/mainwindow.ui \
    forms/tz00s.ui \
    forms/tz20s.ui \
    forms/tz30s.ui \
    forms/tz40s.ui \
    forms/tz50s.ui \
    forms/tz60s.ui \
    forms/tz70s.ui \
    forms/tz80s.ui \
    forms/tz90s.ui \
    forms/tzPresent.ui

RESOURCES += \
    resources.qrc

