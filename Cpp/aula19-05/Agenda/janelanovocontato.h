#ifndef JANELANOVOCONTATO_H
#define JANELANOVOCONTATO_H

#include <QDialog>

namespace Ui {
class JanelaNovoContato;
}

class JanelaNovoContato : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaNovoContato(QWidget *parent = nullptr);
    ~JanelaNovoContato();

private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::JanelaNovoContato *ui;
};

#endif // JANELANOVOCONTATO_H
