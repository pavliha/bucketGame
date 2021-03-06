#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T21:13:29
#
#-------------------------------------------------

QT       += core gui

QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bucket
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Game.cpp \
    Health.cpp \
    main.cpp \
    Player.cpp \
    Score.cpp \
    Bomb.cpp \
    Fruit.cpp \
    dialog.cpp \
    Database.cpp \
    StartGame.cpp


HEADERS += \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    Bomb.h \
    Fruit.h \
    dialog.h \
    Database.h \
    StartGame.h


FORMS += \
    dialog.ui \
    StartGame.ui

RESOURCES += \
    resource.qrc

