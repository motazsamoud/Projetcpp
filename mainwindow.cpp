#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ligne.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QValidator>
#include <QMap>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc;/map.qml")));
    ui->quickWidget->show();
    ui->ajoutid_l->setValidator(new QIntValidator(0, 99999999,  this));
    ui->tableView->setModel(l.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_clicked()
{
    int id_l=ui->ajoutid_l->text().toInt();
    QString depart=ui->ajout_depart->text();
    QString arrive=ui->ajout_arrive->text();
    QString kilometrage=ui->ajout_kilometrage->text();
    QDate date_n=ui->dateEdit->date();


    ligne l(id_l,depart,arrive,kilometrage,date_n);

    bool test=l.ajouter();
    if(test)
    {
        ui->tableView->setModel(l.afficher());
          QMessageBox::information(nullptr, QObject::tr("OK") ,
                                   QObject::tr("Ajout effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);
    }
    else
          QMessageBox::critical(nullptr, QObject::tr("not OK") ,
                                   QObject::tr("Ajout non effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id_l=ui->ajoutid_l->text().toInt();
    bool test=l.supprimer(id_l);
    if(test)
    {

        ui->tableView->setModel(l.afficher());
          QMessageBox::information(nullptr, QObject::tr("OK") ,
                                   QObject::tr("Supression effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);
    }
    else
          QMessageBox::critical(nullptr, QObject::tr("not OK") ,
                                   QObject::tr("Suppression non effectué "
                                               "Clicked Cancel to exit.") , QMessageBox::Cancel);
}

void MainWindow::on_Modifier_clicked()
{
    ligne l;
     int id_l=ui->ajoutid_l->text().toInt();
     QString depart=ui->ajout_depart->text();
     QString arrive=ui->ajout_arrive->text();
     QString kilometrage=ui->ajout_kilometrage->text();

    bool test= l.modifier(id_l,depart,arrive,kilometrage);
     QMessageBox msg;
    if(test)
    {    ui->tableView->setModel(l.afficher());
                    msg.setText("modifie avec succés");

                    }
                    else
                    {
                    msg.setText("Echec au niveau de la modif ");
                    }
                    msg.exec();

                ui->ajoutid_l->clear();
                ui->ajout_depart->clear();
                ui->ajout_arrive->clear();
                ui->ajout_kilometrage->clear();

}



void MainWindow::on_recherche_mod_clicked()
{
    QSqlQuery query;
    query.prepare("select depart, arrive, kilometrage from ligne where id_l=?;");
    query.addBindValue(ui->ajoutid_l->text());
    if(query.exec())
       {
        while(query.next())
         {

    ui->ajout_arrive->setText(query.value(1).toString());
    ui->ajout_depart->setText(query.value(0).toString());
    ui->ajout_kilometrage->setText(query.value(2).toString());


            }
        }
}
