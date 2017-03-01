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
    src/tz40widget.cpp


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
    include/tz40widget.h

FORMS += \
    forms/mainwindow.ui \
    forms/tz40s.ui

RESOURCES += \
    resources.qrc

