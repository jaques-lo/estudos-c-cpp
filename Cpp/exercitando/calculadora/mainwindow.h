#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Números
    void on_btn_0_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();

    // Operadores básicos
    void on_btn_mais_clicked();
    void on_btn_menos_clicked();
    void on_btn_vezes_clicked();
    void on_btn_divisao_clicked();
    void on_btn_igual_clicked();
    void on_btn_virgula_clicked();

    // Parênteses e utilitários
    void on_btn_paraAbre_clicked();
    void on_btn_paraFecha_clicked();
    void on_btn_apagaTudo_clicked();
    void on_pushButton_29_clicked(); // %

    // Científicos (grid esquerdo)
    void on_pushButton_24_clicked(); // deg
    void on_pushButton_25_clicked(); // rad
    void on_pushButton_26_clicked(); // x!
    void on_pushButton_14_clicked(); // inv
    void on_pushButton_15_clicked(); // sin
    void on_pushButton_16_clicked(); // ln
    void on_pushButton_13_clicked(); // pi
    void on_pushButton_12_clicked(); // cos
    void on_pushButton_17_clicked(); // log
    void on_pushButton_10_clicked(); // e
    void on_pushButton_11_clicked(); // tan
    void on_pushButton_18_clicked(); // √
    void on_pushButton_30_clicked(); // Ans
    void on_pushButton_31_clicked(); // EXP (×10^)
    void on_pushButton_32_clicked(); // x^y

private:
    Ui::MainWindow *ui;
    QString expressao;
    double ultimoResultado = 0.0;
    bool modoGraus = true;   // true = graus, false = radianos
    bool modoInv   = false;  // true = funções inversas

    // helpers
    void appendToExpr(const QString &texto);
    void calcular();
    QString prepararExpressao(const QString &expr) const;
    double avaliarComCmath(const QString &expr, bool &ok) const;
};

#endif // MAINWINDOW_H
