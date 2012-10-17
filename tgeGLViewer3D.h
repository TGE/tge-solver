#ifndef TGEGLVIEWER3D_H
#define TGEGLVIEWER3D_H

#include <QtOpenGL/QGLWidget>

#include <string>

#include "linearAlgebra/tgeVector3T.h"

class tgeParticle;
class tgeParticleSystem;

class tgeGLViewer3D : public QGLWidget
{
    Q_OBJECT

public:
    tgeGLViewer3D(QWidget *parent = 0);
	virtual ~tgeGLViewer3D();

protected:

	virtual void initializeGL();
	virtual void resizeGL(int, int);
	virtual void paintGL();
	virtual void mousePressEvent(QMouseEvent*);
	virtual void mouseMoveEvent(QMouseEvent*);
	virtual void wheelEvent(QWheelEvent*);
	virtual void keyPressEvent(QKeyEvent*);

private :

	void drawBackground();
	void drawCornerAxis();
	void drawAxis();
	void drawGrid();
	void drawString(const std::string&, int, int);
	void drawFPS();

	void drawParticles() const;
	void drawParticle(const tgeParticle*) const;

	tgeVector3f	m_translation;
	tgeVector3f	m_rotation;
	QPoint		m_lastPos;

	size_t		m_fps;

	tgeParticleSystem* m_partSystem;
};

#endif // TGEGLVIEWER3D_H
