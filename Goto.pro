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
            Character.cpp \
            Command.cpp \
            CommandWords.cpp \
            item.cpp \
            Parser.cpp \
            Timezone.cpp \
            GoToTime.cpp \
            output.cpp \
    mainwindow.cpp \
    tzportal.cpp \
    tz20.cpp \
    tz30.cpp \
    tz40.cpp \
    tz50.cpp \
    tz60.cpp \
    tz70.cpp \
    tz80.cpp \
    tz90.cpp \
    tz00.cpp \
    tzpresent.cpp


HEADERS  += \
            Character.h \
            Command.h \
            CommandWords.h \
            item.h \
            Parser.h \
            Timezone.h \
            GoToTime.h \
            output.h \
    mainwindow.h \
    tzportal.h \
    tz20.h \
    tz30.h \
    tz40.h \
    tz50.h \
    tz60.h \
    tz70.h \
    tz80.h \
    tz90.h \
    tz00.h \
    tzpresent.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

