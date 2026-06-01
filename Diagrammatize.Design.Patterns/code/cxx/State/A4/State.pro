#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T19:26:40
#
#-------------------------------------------------

QT       += core gui

TARGET = State
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += Main.cpp \
            Context.cpp\
            DayState.cpp\
            NightState.cpp\
            UrgentState.cpp\
            SafeFrame.cpp\
            State.cpp

HEADERS  += Context.hpp\
            DayState.hpp\
            NightState.hpp\
            UrgentState.hpp\
            SafeFrame.hpp\
            State.hpp

RESOURCES += 
