#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T14:35:27
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = tge-solver
TEMPLATE = app

INCLUDEPATH += /tge-src/boost_1_48_0
LIBS += -lglut -lGL

SOURCES += main.cpp\
			tgeGLViewer3D.cpp \
			linearAlgebra/tgeVector3T.cpp \
    dynamics/tgeParticle.cpp \
    dynamics/tgeParticleSystem.cpp \
    dynamics/tgeGravityForce.cpp \
    dynamics/tgeEmitter.cpp

HEADERS  += tgeGLViewer3D.h \
			linearAlgebra/tgeVector3T.h \
			linearAlgebra/tgeVector3T.hpp \
			utils/tgeUtils.h \
			utils/tgeTimer.h \
    dynamics/tgeParticle.h \
    dynamics/tgeParticleSystem.h \
    dynamics/tgeGravityForce.h \
    dynamics/tgeEmitter.h
