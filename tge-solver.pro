#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T14:35:27
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = tge-solver
TEMPLATE = app

LIBS += -lglut -lGL

SOURCES += main.cpp\
        tgeGLViewer3D.cpp \
    tgeVector3T.cpp

HEADERS  += tgeGLViewer3D.h \
    tgeVector3T.h \
    tgeVector3T.hpp
