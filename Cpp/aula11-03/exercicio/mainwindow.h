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
    void on_btn_janela2_clicked();

    void on_btn_carrega_clicked();

    void on_btn_testa_clicked();

private:
    Ui::MainWindow *ui;
    QString palavra, palavraAdivinha;
    QChar letra;
    //int erros = 0;
};
#endif // MAINWINDOW_H
