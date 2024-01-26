#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T19:26:40
#
#-------------------------------------------------

QT       += core gui

TARGET = Observer
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += Main.cpp \
        Random.cpp\
        Observer.cpp\
	    DigitObserver.cpp\
	    GraphObserver.cpp\
	    NumberGenerator.cpp\
	    RandomNumberGenerator.cpp\
        FrameObserver.cpp

HEADERS  += Random.hpp\
        Observer.hpp\
        DigitObserver.hpp\
        GraphObserver.hpp\
        NumberGenerator.hpp\
        RandomNumberGenerator.hpp\
        FrameObserver.hpp

RESOURCES += 
