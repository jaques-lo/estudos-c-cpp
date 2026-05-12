#ifndef JANELALOGIN_H
#define JANELALOGIN_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class JanelaLogin;
}

class JanelaLogin : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaLogin(QWidget *parent = nullptr);
    ~JanelaLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::JanelaLogin *ui;
   QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // JANELALOGIN_H
