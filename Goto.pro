#-------------------------------------------------
#
# Project created by QtCreator 2017-02-01T10:22:20
#
#-------------------------------------------------

QT       += core gui

CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Zork
TEMPLATE = app


SOURCES  += \
            Character.cpp \
            Command.cpp \
            CommandWords.cpp \
            item.cpp \
            Parser.cpp \
            Timezone.cpp \
    GoToTime.cpp \
    output.cpp


HEADERS  += \
            Character.h \
            Command.h \
            CommandWords.h \
            item.h \
            Parser.h \
            Timezone.h \
    GoToTime.h \
    output.h

