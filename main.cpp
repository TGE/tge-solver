#include <QtGui/QApplication>
#include "tgeGLViewer3D.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	tgeGLViewer3D viewer;
	viewer.show();

    return a.exec();
}
