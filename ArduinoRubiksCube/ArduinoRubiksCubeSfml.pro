TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += sfmlmain.cpp \
    sfmlrubikscube.cpp \
    rubikscube.cpp

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Weffc++
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sfmlrubikscube.h \
    rubikscube.h

