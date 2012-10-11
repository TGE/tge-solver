#ifndef TGEGLVIEWER3D_H
#define TGEGLVIEWER3D_H

#include <QtOpenGL/QGLWidget>

class tgeGLViewer3D : public QGLWidget
{
    Q_OBJECT

public:
    tgeGLViewer3D(QWidget *parent = 0);
    ~tgeGLViewer3D();
};

#endif // TGEGLVIEWER3D_H
