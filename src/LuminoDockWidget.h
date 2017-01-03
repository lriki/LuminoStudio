
#pragma once
#include "Core/EditorInterface.h"

class LuminoDockWidget
	: public QDockWidget
	, public ls::IEditorPane
{
	Q_OBJECT
public:
	LuminoDockWidget(const QString &title, QWidget* parent = 0);
	virtual ~LuminoDockWidget();

};
