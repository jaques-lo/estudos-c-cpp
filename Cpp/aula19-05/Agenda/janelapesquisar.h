#ifndef JANELAPESQUISAR_H
#define JANELAPESQUISAR_H

#include <QDialog>

namespace Ui {
class JanelaPesquisar;
}

class JanelaPesquisar : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaPesquisar(QWidget *parent = nullptr);
    ~JanelaPesquisar();

private slots:
    void on_btn_excluir_clicked();

    void on_btn_editar_clicked();

private:
    Ui::JanelaPesquisar *ui;
};

#endif // JANELAPESQUISAR_H
