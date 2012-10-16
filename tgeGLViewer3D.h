#ifndef TGEGLVIEWER3D_H
#define TGEGLVIEWER3D_H

#include <QtOpenGL/QGLWidget>
#include <tgeVector3T.h>

class tgeGLViewer3D : public QGLWidget
{
    Q_OBJECT

public:
    tgeGLViewer3D(QWidget *parent = 0);
    ~tgeGLViewer3D();

protected:

	virtual void initializeGL();
	virtual void resizeGL(int, int);
	virtual void paintGL();
	virtual void mousePressEvent( QMouseEvent* );
	virtual void mouseMoveEvent( QMouseEvent* );

private :

	void drawBackground();
	void drawAxis();
	void drawGrid();

	tgeVector3f	m_translation;
	tgeVector3f	m_rotation;
	QPoint		m_lastPos;
};

#endif // TGEGLVIEWER3D_H
