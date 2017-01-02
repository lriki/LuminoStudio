
#include "LuminoViewWidget.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);



	//ln::EngineSettings::SetGraphicsAPI(ln::GraphicsAPI::OpenGL);
	ln::EngineSettings::SetUserWindowHandle(this->winId());
	ln::Engine::Initialize();
	ln::Engine::GetMainViewport()->SetBackgroundColor(ln::Color32::Gray);

	ln::Engine::Update();



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
	//QTextEdit* editor1 = new QTextEdit(tr("1"), tabWidget);
	QTextEdit* editor2 = new QTextEdit(tr("2"), tabWidget);
	LuminoViewWidget* lnW = new LuminoViewWidget(tabWidget);
	lnW->initialize();
	tabWidget->addTab(lnW, tr("TAB1"));
	tabWidget->addTab(editor2, tr("TAB2"));
	//tabWidget->setTabClosable(true);
	tabWidget->setTabsClosable(true);
	tabWidget->setMovable(true);
	setCentralWidget(tabWidget);

	connect(this, SIGNAL(closed()), this, SLOT(onClosed()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::menuSelected()
{

}

void MainWindow::onClosed()
{
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	// �h�L�������g���ύX����Ă���ꍇ�̌x��
	QMessageBox::StandardButton res = QMessageBox::question(this, tr("title"), tr("w"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

	switch (res)
	{
	case QMessageBox::Yes:
		// �ۑ��ł����Ȃ�A����OK
		event->ignore();
		//if (saved())  event->accept();
		break;

	case QMessageBox::No:
		// �ۑ����Ȃ��āA���̂܂ܕ���OK
		event->accept();
		break;

	case QMessageBox::Cancel:
		// �L�����Z�����č�Ƃɖ߂�
		event->ignore();
		break;

	default:
		break;
	}
}
