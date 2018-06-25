#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug";
#include "msgdialog.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  //inizializzo i valori della cella
  m_celle[0][0]=ui->cella_00;
  m_celle[0][1]=ui->cella_01;
  m_celle[0][2]=ui->cella_02;
  m_celle[1][0]=ui->cella_10;
  m_celle[1][1]=ui->cella_11;
  m_celle[1][2]=ui->cella_12;
  m_celle[2][0]=ui->cella_20;
  m_celle[2][1]=ui->cella_21;
  m_celle[2][2]=ui->cella_22;

  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          connect(m_celle[i][j],SIGNAL(clicked(bool)),this,SLOT(funzione()));
        }
    }

}
MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::funzione()
{

  QObject* obj= sender();
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          if(obj == m_celle[i][j] ){
              if(stato(i,j)==""){
                  qInfo()<<"cella premuta"<<i<<" "<<j;
                  m_celle[i][j]->setText(m_giocatore);
                  if(vittoria()){
                      QString c="ha vinto il giocatore "+m_giocatore;
                      MsgDialog d{c};
                      d.exec();
                    }
                  else if(!check()){
                      QString c="NESSUNO HA VINTO";
                      MsgDialog v{c};
                      v.exec();
                    }
                  invertiGiocatore();
                }
            }
        }
    }
}

// Ritorna vero se le condizioni di vittoria sono soddisfatte
bool MainWindow::vittoria()
{
  return (stato(0,0) == stato(0,1) && stato(0,1) == stato(0,2) &&
          stato(0,2) != ""
      || stato(1,0) == stato(1,1) && stato(1,1) == stato(1,2) &&
      stato(1,2) != ""
      || stato(2,0) == stato(2,1) && stato(2,1) == stato(2,2) &&
      stato(2,2) != ""
      || stato(0,0) == stato(1,0) && stato(1,0) == stato(2,0) &&
      stato(2,0) != ""
      || stato(0,1) == stato(1,1) && stato(1,1) == stato(2,1) &&
      stato(2,1) != ""
      || stato(0,2) == stato(1,2) && stato(1,2) == stato(2,2) &&
      stato(2,2) != ""
      || stato(0,0) == stato(1,1) && stato(1,1) == stato(2,2) &&
      stato(2,2) != ""
      || stato(2,0) == stato(1,1) && stato(1,1) == stato(0,2) &&
      stato(0,2) != "");
}
// Ritorna lo stato della cella: "" (vuota), "O", "X"
QString MainWindow::stato(int riga, int colonna)
{
  return m_celle[riga][colonna]->text();
}

void MainWindow::invertiGiocatore()
{
  if(m_giocatore=="X"){
      m_giocatore="O";
    }else{
      m_giocatore="X";
    }
}

bool MainWindow::check()
{
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
          if(stato(i,j)== ""){
              return true;
            }
        }
    }
  return false;

}
