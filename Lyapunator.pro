#-------------------------------------------------
#
# Project created by QtCreator 2018-01-01T23:08:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lyapunator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    processor.cpp \
    arguments.cpp

HEADERS  += mainwindow.h \
    processor.h \
    arguments.h

FORMS    += mainwindow.ui \
    arguments.ui
