#include "LuminoViewWidget.h"

LuminoViewWidget::LuminoViewWidget(QWidget *parent)
	: QWidget(parent)//QGLWidget(parent)
{
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoSystemBackground);
}

LuminoViewWidget::~LuminoViewWidget()
{
	dispose();
}

void LuminoViewWidget::initialize()
{
	m_host = ln::UINativeHostWindow::Create(winId());
	m_host->GetViewport()->SetBackgroundColor(ln::Color::Gray);
}

void LuminoViewWidget::dispose()
{
}

void LuminoViewWidget::paintEvent(QPaintEvent *e)
{
	Q_UNUSED(e);
	//ln::Engine::Update();

	printf("a\n");

	m_host->Render();
}

//void LuminoGLWidget::initializeGL()
//{
//	glClearColor(0.1, 0.1, 0.1, 1);
//}
//
//void LuminoGLWidget::paintGL()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex3f(-0.5, -0.5, 0);
//	glColor3f(0, 1, 0);
//	glVertex3f(0.5, -0.5, 0);
//	glColor3f(0, 0, 1);
//	glVertex3f(0, 0.5, 0);
//	glEnd();
//
//}
//
//void LuminoGLWidget::resizeGL(int w, int h)
//{
//}
