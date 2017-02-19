
#include "MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile f(":qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		qApp->setStyleSheet(ts.readAll());
	}

	QFont font("Meiryo UI");
	a.setFont(font);
	
	int exitCode;
	{
		MainWindow w;
		w.show();
		exitCode = a.exec();
		w.dispose();
	}
	ln::Engine::Terminate();
	return exitCode;
}
