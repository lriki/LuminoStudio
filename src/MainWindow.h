#ifndef LUMINOSTUDIO_H
#define LUMINOSTUDIO_H

#include <QtWidgets/QMainWindow>
#include "Core/EditorInterface.h"
//#include "ui_luminostudio.h"

class MainWindow
	: public QMainWindow
	, public ls::IEditor
	, public ls::IEditorWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	virtual ~MainWindow();
	void dispose();

	// IEditor interface
	virtual ls::IEditorWindow* GetMainWindow() override;

	// IEditorWindow interface
	virtual ls::IEditorPane* CreateDockablePane(const ln::String& id, ls::DockingArea area) override;


private slots:
	void onNewProject();
	void onOpenProject();
	void menuSelected();

	void onClosed();

private:
	virtual void closeEvent(QCloseEvent* event) override;
	//Ui::LuminoStudioClass ui;
};

#endif // LUMINOSTUDIO_H
