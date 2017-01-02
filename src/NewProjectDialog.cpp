#include "NewProjectDialog.h"

NewProjectDialog::NewProjectDialog(QWidget* parent)
	: QDialog(parent)
{
	QVBoxLayout* layout = new QVBoxLayout(this);

	m_buttonBox = new QDialogButtonBox(this);
	m_buttonBox->addButton(QDialogButtonBox::Ok);
	m_buttonBox->addButton(QDialogButtonBox::Cancel);

	connect(m_buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(m_buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	m_editProjectName = new QLineEdit(this);
	m_editProjectName->resize(100, 30);


	layout->addWidget(m_editProjectName);
	layout->addWidget(m_buttonBox, 0, Qt::AlignBottom);
	setLayout(layout);
}
