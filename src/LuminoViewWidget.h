
#pragma once
#include <QGLWidget>

class LuminoViewWidget
	: public QWidget//QGLWidget
{
	Q_OBJECT
public:
	explicit LuminoViewWidget(QWidget *parent = 0);
	virtual ~LuminoViewWidget();

	void initialize();
	void dispose();

	virtual void	paintEvent(QPaintEvent *e);

signals:
public slots:

protected:
	virtual QPaintEngine* paintEngine() const override { return 0; }

private:
	ln::UINativeHostWindowPtr	m_host;
};
