#ifndef LIGNE_H
#define LIGNE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
class ligne
{

public:
    ligne(){}
    ligne(int,QString,QString,QString,QDate);//constructeur par defaut

    QString getdepart(){return depart;}
    QString getarrive(){return arrive;}
    QString getkilometrage(){return kilometrage;}



    int getid_l(){return id_l;}


    void setdepart(QString d){depart=d;}
    void setarrive(QString a){arrive=a;}
    void setid_l(int id_l){this->id_l=id_l;}
    void setkilometrage(QString k){kilometrage=k;}
    void setdate_n(QDate date_n){this ->date_n=date_n;}

    bool ajouter();
    QSqlQueryModel* afficher();
bool supprimer(int);
bool modifier(int,QString,QString,QString);

private:
int id_l;
QString depart, arrive,kilometrage;
QDate date_n;
};
#endif // LIGNE_H




