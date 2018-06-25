#include "msgdialog.h"
#include "ui_msgdialog.h"
MsgDialog::MsgDialog(const QString& messaggio, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MsgDialog)
{
  ui->setupUi(this);
  ui->label->setText(messaggio);
}
MsgDialog::~MsgDialog()
{
  delete ui;
}
