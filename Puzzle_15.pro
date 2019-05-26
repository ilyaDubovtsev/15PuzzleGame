#-------------------------------------------------
#
# Project created by QtCreator 2015-12-01T19:14:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Puzzle_15
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form.cpp \
    Game.cpp \


HEADERS  += mainwindow.h \
    Game.h \ \
    form.h


FORMS    += mainwindow.ui \
    form.ui

RESOURCES += \
    pictures.qrc
