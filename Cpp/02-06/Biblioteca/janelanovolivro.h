#ifndef JANELANOVOLIVRO_H
#define JANELANOVOLIVRO_H

#include <QDialog>

namespace Ui {
class JanelaNovoLivro;
}

class JanelaNovoLivro : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaNovoLivro(QWidget *parent = nullptr);
    ~JanelaNovoLivro();

private slots:
    void on_btn_gravar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::JanelaNovoLivro *ui;
};

#endif // JANELANOVOLIVRO_H
