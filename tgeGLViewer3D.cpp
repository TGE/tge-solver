#include "tgeGLViewer3D.h"

#include <QtGui/QMouseEvent>

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>
#include <sstream>
#include <iomanip>

#include "linearAlgebra/tgeVector3T.hpp"
#include "utils/tgeTimer.h"

tgeGLViewer3D::tgeGLViewer3D(QWidget *parent) :
	QGLWidget(parent),
	m_translation(0.f, -3.f, -25.f),
	m_rotation(10.f, -25.f, 0.f)
{}

tgeGLViewer3D::~tgeGLViewer3D()
{}

void tgeGLViewer3D::initializeGL()
{
	glClearColor(0.8, 0.8, 0.8, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
}

void tgeGLViewer3D::resizeGL(int w, int h)
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 60.0, (float) w / (float) h, 0.1, 100.0 );

	glMatrixMode( GL_MODELVIEW );
	glViewport( 0, 0, w, h );
}

void tgeGLViewer3D::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawBackground();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective( 60.0, (float) width() / (float) height(), 0.1, 100.0 );

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glTranslatef( m_translation[0], m_translation[1], m_translation[2] );
	glRotatef( m_rotation[0], 1.0, 0.0, 0.0 );
	glRotatef( m_rotation[1], 0.0, 1.0, 0.0 );
	glRotatef( m_rotation[2], 0.0, 0.0, 1.0 );

	drawGrid();
	drawAxis();
	drawCornerAxis();
	drawFPS();

	swapBuffers();
}

void tgeGLViewer3D::mousePressEvent( QMouseEvent* aEvent )
{
	m_lastPos = aEvent->pos();
}

void tgeGLViewer3D::mouseMoveEvent( QMouseEvent* aEvent )
{
	GLfloat dx = GLfloat( aEvent->x() - m_lastPos.x() ) / width();
	GLfloat dy = GLfloat( aEvent->y() - m_lastPos.y() ) / height();

	if ( aEvent->buttons() & Qt::LeftButton ) // ORBIT
	{
		m_rotation[0] += 180 * dy;
		m_rotation[1] += 180 * dx;
		updateGL();
	}
	else if ( aEvent->buttons() & Qt::MidButton ) // PAN
	{
		m_translation[0] += dx * 20.f;
		m_translation[1] -= dy * 20.f;
		updateGL();
	}
	else if ( aEvent->buttons() & Qt::RightButton ) // ZOOM
	{
		m_translation[2] += dx * fabs( m_translation[2] );
		updateGL();
	}

	m_lastPos = aEvent->pos();
}

void tgeGLViewer3D::wheelEvent(QWheelEvent *event)
{
	const int delta = event->delta();
	m_translation[2] += delta/fabs(delta);
	updateGL();
}

void tgeGLViewer3D::drawBackground()
{
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glBegin(GL_QUADS);
		glColor3f( 0.8f, 0.8f, 0.9f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f( 1.0f, 1.0f, 0.0f);
		glColor3f( 0.1f, 0.1f, 0.2f);
		glVertex3f( 1.0f,-1.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
	glEnd();
}

void tgeGLViewer3D::drawCornerAxis()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1);
	glViewport(0, 0, 50, 50);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef( m_rotation[0], 1.0, 0.0, 0.0 );
	glRotatef( m_rotation[1], 0.0, 1.0, 0.0 );
	glRotatef( m_rotation[2], 0.0, 0.0, 1.0 );

	drawAxis();

	glViewport(0, 0, width(), height());
}

void tgeGLViewer3D::drawAxis()
{
	glLineWidth( 2.0 );

	glBegin( GL_LINES );

	glColor3f( 1.f, 0.f, 0.f );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 1, 0, 0 );
	glColor3f( 0.f, 1.f, 0.f );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 1, 0 );
	glColor3f( 0.f, 0.f, 1.f );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 0, 1 );

	glEnd();
}

void tgeGLViewer3D::drawGrid()
{
	glColor3f(0.2f, 0.2f, 0.2f);
	glEnable( GL_LINE_STIPPLE );
	glLineStipple( 1, 0xAAAA );
	glLineWidth( 1 );

	glBegin( GL_LINES );

	for ( int i = -10; i < 0; ++i )
	{
		//--- X
		glVertex3f( i, 0, -10 );
		glVertex3f( i, 0, 10 );

		//--- Z
		glVertex3f( -10, 0, i );
		glVertex3f( 10, 0, i );
	}

	for ( uint i = 1; i <= 10; ++i )
	{
		glVertex3f( i, 0, -10 );
		glVertex3f( i, 0, 10 );

		glVertex3f( -10, 0, i );
		glVertex3f( 10, 0, i );
	}

	glEnd();

	glDisable( GL_LINE_STIPPLE );

	glBegin(GL_LINES );
		glVertex3f( -10, 0, 0 );
		glVertex3f( 10, 0, 0 );

		glVertex3f( 0, 0, -10 );
		glVertex3f( 0, 0, 10 );
	glEnd();
}

void tgeGLViewer3D::drawString(const std::string& string,
							   int x, int y)
{
	glPushAttrib(GL_LIGHTING_BIT | GL_CURRENT_BIT);
	glDisable(GL_LIGHTING);

	glRasterPos2i(x, y);

	const char* str = string.c_str();
	while(*str)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *str);
		++str;
	}

	glEnable(GL_LIGHTING);
	glPopAttrib();
}

void tgeGLViewer3D::drawFPS()
{
	static tgeTimer timer;
	static int count = 0;
	static std::stringstream ss;
	double elapsedTime;

	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width(), 0, height());

	elapsedTime = timer.getElapsedTime();

	if(elapsedTime < 1.0)
	{
		++count;
	}
	else
	{
		ss.str("");
		ss << std::fixed << std::setprecision(1);
		ss << (count / elapsedTime) << " FPS" << std::ends;
		ss << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);

		count = 0;
		timer.start();
	}

	static const float color[4] = {1, 1, 1, 1};
	glColor4fv( color );
	drawString( ss.str(), width()-80, height()-20);

	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}
