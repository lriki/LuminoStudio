#ifndef LUMINOSTUDIO_H
#define LUMINOSTUDIO_H

#include <QtWidgets/QMainWindow>
//#include "ui_luminostudio.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();

private slots:
	void onNewProject();
	void menuSelected();

	void onClosed();

private:
	virtual void closeEvent(QCloseEvent* event) override;
	//Ui::LuminoStudioClass ui;
};

#endif // LUMINOSTUDIO_H
