#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QString>
namespace Ui {
  class MainWindow;
}
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
public slots:
  void funzione();
private:
  // Ritorna lo stato della cella: "" (vuota), "O", "X"
  QString stato(int riga, int colonna);
  QString m_giocatore{"X"};
  void invertiGiocatore();
  bool check();
  // Ritorna vero se le condizioni di vittoria sono soddisfatte
  bool vittoria();
  // Array con puntatori ai widget dell'interfaccia grafica
  QPushButton* m_celle[3][3];
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
