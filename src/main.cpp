
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	

	MainWindow w;
	w.show();
	int exitCode = a.exec();

	ln::Engine::Terminate();
	return exitCode;
}
