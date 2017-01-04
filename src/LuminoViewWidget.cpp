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
	m_host->GetViewport()->SetPlacement(ln::ViewportPlacement::AutoResize);

	m_sceneGraph2D = ln::SceneGraph2D::Create();
	m_cameraViewportLayer2D = ln::CameraViewportLayer::Create(m_sceneGraph2D->GetMainCamera());

	m_host->GetViewport()->GetLayers()->Insert(0, m_cameraViewportLayer2D);

	m_sp = ln::Sprite2D::Create(_T("D:/GameProjects/Chronicles/110220c_as019.jpg"));
	m_sceneGraph2D->GetRootNode()->AddChild(m_sp);
}

void LuminoViewWidget::dispose()
{
}

void LuminoViewWidget::paintEvent(QPaintEvent *e)
{
	Q_UNUSED(e);

	m_host->Render();
}

void LuminoViewWidget::resizeEvent(QResizeEvent* e)
{
	ln::PlatformEventArgs args = ln::PlatformEventArgs::MakeWindowSizeChangedEvent(m_host->GetPlatformWindow(), e->size().width(), e->size().height());
	m_host->GetPlatformWindow()->SendPlatformEvent(args);
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
