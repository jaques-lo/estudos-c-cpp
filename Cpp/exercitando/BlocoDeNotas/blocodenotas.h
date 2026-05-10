#ifndef BLOCODENOTAS_H
#define BLOCODENOTAS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class BlocoDeNotas;
}
QT_END_NAMESPACE

class BlocoDeNotas : public QMainWindow
{
    Q_OBJECT

public:
    BlocoDeNotas(QWidget *parent = nullptr);
    ~BlocoDeNotas();

private slots:
    void on_actionnovo_triggered();

    void on_actionabrir_triggered();

    void on_actionsalvar_como_triggered();

    void on_actionsalvar_triggered();

    void on_actionsair_triggered();

    void on_actionRecortar_triggered();

    void on_actionCopiar_triggered();

    void on_actionColar_triggered();

    void on_actionDesfazer_triggered();

    void on_actionRefazer_triggered();

    void on_actionFonte_triggered();

    void on_actionCor_triggered();

    void on_actionCor_de_Fundo_triggered();

    void on_actionPrimeiro_Software_QT_triggered();

    void on_actionimprimir_triggered();

private:
    Ui::BlocoDeNotas *ui;
    QString local_arquivo;
};
#endif // BLOCODENOTAS_H
