#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QIntValidator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_ID->setValidator(new QIntValidator(0, 9999999,  this));
    ui->tableView->setModel(Etmp.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_3_clicked()

    {
        int id=ui->lineEdit_ID->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        Etudiant E(id,nom,prenom);

        bool test=E.ajouter();
        if(test)
        {
              QMessageBox::information(nullptr, QObject::tr("OK") ,
                                       QObject::tr("Ajout effectué "
                                                   "Clicked Cancel to exit.") , QMessageBox::Cancel);
        }
        else
              QMessageBox::critical(nullptr, QObject::tr("not OK") ,
                                       QObject::tr("Ajout non effectué "
                                                   "Clicked Cancel to exit.") , QMessageBox::Cancel);

    }


void MainWindow::on_pushButton_supprimer_2_clicked()
{
    int id=ui->lineEdit_ID_2->text().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {
          QMessageBox::information(nullptr, QObject::tr("OK") ,
                                   QObject::tr("Supression effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);
    }
    else
          QMessageBox::critical(nullptr, QObject::tr("not OK") ,
                                   QObject::tr("Suppression non effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);

}
