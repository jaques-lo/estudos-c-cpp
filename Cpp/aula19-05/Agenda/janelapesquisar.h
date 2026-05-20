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

private:
    Ui::JanelaPesquisar *ui;
};

#endif // JANELAPESQUISAR_H
