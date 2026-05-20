#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class JanelaPrincipal;
}
QT_END_NAMESPACE

class JanelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    JanelaPrincipal(QWidget *parent = nullptr);
    ~JanelaPrincipal();

private slots:
    void on_btn_adicionar_clicked();

    void on_btn_pesquisar_clicked();

private:
    Ui::JanelaPrincipal *ui;
};
#endif // JANELAPRINCIPAL_H
