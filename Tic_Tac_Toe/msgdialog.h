#ifndef MSGDIALOG_H
#define MSGDIALOG_H
#include <QDialog>
#include <ui_msgdialog.h>
#include<QString>
namespace Ui {
  class MsgDialog;
}
class MsgDialog : public QDialog
{
  Q_OBJECT
public:
  explicit MsgDialog(const QString& messaggio, QWidget *parent = 0);
  ~MsgDialog();
private:
  Ui::MsgDialog *ui;
};
#endif // MSGDIALOG_H
