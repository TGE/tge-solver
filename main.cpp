#include <QtGui/QApplication>
#include "tgeGLViewer3D.h"

#include <GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	glutInit(&argc, argv);

	tgeGLViewer3D viewer;
	viewer.setWindowTitle(QObject::tr("tge-solver"));
	viewer.resize(1024, 728);
	viewer.show();

    return a.exec();
}
