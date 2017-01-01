
#include "luminostudio.h"

LuminoStudio::LuminoStudio(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);

	// �t�@�C�����j���[�̍��ڂ��쐬����
	QAction* newAction = new QAction(tr("New project(&N)"), this);
	newAction->setStatusTip(tr("Create a new project."));

	QAction* saveAction = new QAction(tr("Save(&S)"), this);
	saveAction->setStatusTip(tr("Save project."));

	QAction* quitAction = new QAction(tr("Exit(&Q)"), this);
	quitAction->setStatusTip(tr("Exit application."));

	// �V�O�i���ƃX���b�g��ڑ�����
	connect(newAction, SIGNAL(triggered()), this, SLOT(menuSelected()));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(menuSelected()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

	// �t�@�C�����j���[���쐬����
	QMenu* fileMenu = this->menuBar()->addMenu(tr("File(&F)"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(quitAction);

	QTabWidget* tabWidget = new QTabWidget(this);
	QTextEdit* editor1 = new QTextEdit(tr("1"), tabWidget);
	QTextEdit* editor2 = new QTextEdit(tr("2"), tabWidget);
	tabWidget->addTab(editor1, tr("TAB1"));
	tabWidget->addTab(editor2, tr("TAB2"));
	//tabWidget->setTabClosable(true);
	tabWidget->setTabsClosable(true);
	tabWidget->setMovable(true);
	setCentralWidget(tabWidget);


}

LuminoStudio::~LuminoStudio()
{

}

void LuminoStudio::menuSelected()
{

}