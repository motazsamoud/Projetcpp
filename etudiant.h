#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QMessageBox>
class Etudiant
{

public:
    Etudiant(){}
    Etudiant(int,QString,QString);

    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getID(){return id;}


    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setID(int id){this->id=id;}

    bool ajouter();
    QSqlQueryModel* afficher();
bool supprimer(int);

private:
int id;
QString nom, prenom;
};
#endif // ETUDIANT_H
