
#pragma once

class NewProjectDialog
	: public QDialog
{
	Q_OBJECT
public:
	explicit NewProjectDialog(QWidget* parent = 0);
	virtual ~NewProjectDialog() = default;

signals:
public slots :

private:
	QDialogButtonBox*	m_buttonBox;
	QLineEdit*			m_editProjectName;
};
