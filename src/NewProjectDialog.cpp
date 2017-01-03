#include "NewProjectDialog.h"
#include "ui_NewProjectDialog.h"

NewProjectDialog::NewProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProjectDialog)
{
    ui->setupUi(this);
}

NewProjectDialog::~NewProjectDialog()
{
    delete ui;
}

QString NewProjectDialog::GetProjectName() const
{
	return ui->lineEdit->text();
}

QString NewProjectDialog::GetProjectTitle() const
{
	return ui->lineEdit_2->text();
}

QString NewProjectDialog::GetProjectPath() const
{
	return ui->lineEdit_3->text();
}
