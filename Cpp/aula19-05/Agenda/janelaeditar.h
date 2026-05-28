#ifndef JANELAEDITAR_H
#define JANELAEDITAR_H

#include <QDialog>

namespace Ui {
class JanelaEditar;
}

class JanelaEditar : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaEditar(int id_contato, QWidget *parent = nullptr);
    ~JanelaEditar();

private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::JanelaEditar *ui;
    int id;
};

#endif // JANELAEDITAR_H
