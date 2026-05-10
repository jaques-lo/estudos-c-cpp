#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_salvar_clicked();

    void on_btn_dados_clicked();

    void on_chk_femea_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QString nome;
    int idade;
    QString sexo;
};
#endif // MAINWINDOW_H
