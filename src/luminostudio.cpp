
#include "luminostudio.h"

LuminoStudio::LuminoStudio(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	// ファイルメニューの項目を作成する
	QAction* newAction = new QAction(tr("New project(&N)"), this);
	newAction->setStatusTip(tr("Create a new project."));

	QAction* saveAction = new QAction(tr("Save(&S)"), this);
	saveAction->setStatusTip(tr("Save project."));

	QAction* quitAction = new QAction(tr("Exit(&Q)"), this);
	quitAction->setStatusTip(tr("Exit application."));

	// シグナルとスロットを接続する
	connect(newAction, SIGNAL(triggered()), this, SLOT(menuSelected()));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(menuSelected()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

	// ファイルメニューを作成する
	QMenu* fileMenu = this->menuBar()->addMenu(tr("File(&F)"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAction);
}

LuminoStudio::~LuminoStudio()
{

}

void LuminoStudio::menuSelected()
{

}
