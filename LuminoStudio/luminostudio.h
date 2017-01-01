#ifndef LUMINOSTUDIO_H
#define LUMINOSTUDIO_H

#include <QtWidgets/QMainWindow>
#include "ui_luminostudio.h"

class LuminoStudio : public QMainWindow
{
	Q_OBJECT

public:
	LuminoStudio(QWidget *parent = 0);
	~LuminoStudio();

private:
	Ui::LuminoStudioClass ui;
};

#endif // LUMINOSTUDIO_H
