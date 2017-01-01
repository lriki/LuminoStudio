#include "stdafx.h"
#include "luminostudio.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LuminoStudio w;
	w.show();
	return a.exec();
}
