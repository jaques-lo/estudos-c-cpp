#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QRegularExpression>

struct Parser {
    QString s;
    int pos = 0;
    bool graus = true;
    bool erro  = false;

    QChar cur() { return (pos < s.size()) ? s[pos] : QChar(0); }
    void skip() { while (pos < s.size() && s[pos].isSpace()) ++pos; }

    double parseExpr();
    double parseTerm();
    double parsePow();
    double parseUnary();
    double parseAtom();
};

double Parser::parseExpr()
{
    double val = parseTerm();
    skip();
    while (!erro && (cur() == '+' || cur() == '-')) {
        QChar op = cur(); ++pos;
        double r = parseTerm();
        val = (op == '+') ? val + r : val - r;
        skip();
    }
    return val;
}

double Parser::parseTerm()
{
    double val = parsePow();
    skip();
    while (!erro && (cur() == '*' || cur() == '/')) {
        QChar op = cur(); ++pos;
        double r = parsePow();
        if (op == '/' && r == 0.0) { erro = true; return 0; }
        val = (op == '*') ? val * r : val / r;
        skip();
    }
    return val;
}

double Parser::parsePow()
{
    double base = parseUnary();
    skip();
    if (!erro && cur() == '^') {
        ++pos;
        double exp = parseUnary();
        base = qPow(base, exp);
    }
    return base;
}

double Parser::parseUnary()
{
    skip();
    if (cur() == '-') { ++pos; return -parseAtom(); }
    if (cur() == '+') { ++pos; return  parseAtom(); }
    return parseAtom();
}

double Parser::parseAtom()
{
    skip();
    if (erro) return 0;

    if (cur() == '(') {
        ++pos;
        double val = parseExpr();
        skip();
        if (cur() == ')') ++pos;
        return val;
    }

    if (cur().isDigit() || cur() == '.') {
        int start = pos;
        while (cur().isDigit() || cur() == '.' || cur() == 'e' || cur() == 'E' ||
               ((cur() == '+' || cur() == '-') && pos > 0 &&
                (s[pos-1] == 'e' || s[pos-1] == 'E')))
            ++pos;
        bool ok;
        double v = s.mid(start, pos - start).toDouble(&ok);
        if (!ok) erro = true;
        return v;
    }

    if (cur().isLetter()) {
        int start = pos;
        while (cur().isLetter()) ++pos;
        QString nome = s.mid(start, pos - start).toLower();
        skip();

        if (nome == "pi") return M_PI;
        if (nome == "e")  return M_E;

        if (nome == "fat") {
            ++pos;
            double n = parseExpr();
            skip(); if (cur() == ')') ++pos;
            int ni = qRound(n);
            double f = 1.0;
            for (int i = 2; i <= ni && i <= 170; ++i) f *= i;
            return f;
        }

        if (cur() == '(') {
            ++pos;
            double arg = parseExpr();
            skip(); if (cur() == ')') ++pos;

            if (nome == "sqrt") return qSqrt(arg);
            if (nome == "log")  return qLn(arg) / qLn(10.0);
            if (nome == "ln")   return qLn(arg);
            if (nome == "abs")  return qAbs(arg);

            double rad = graus ? qDegreesToRadians(arg) : arg;
            if (nome == "sin")  return qSin(rad);
            if (nome == "cos")  return qCos(rad);
            if (nome == "tan")  return qTan(rad);

            double res;
            if      (nome == "asin") res = qAsin(arg);
            else if (nome == "acos") res = qAcos(arg);
            else if (nome == "atan") res = qAtan(arg);
            else { erro = true; return 0; }
            return graus ? qRadiansToDegrees(res) : res;
        }
        erro = true;
        return 0;
    }

    erro = true;
    return 0;
}

static double avaliar(const QString &expr, bool graus, bool &ok)
{
    Parser p;
    p.s     = expr;
    p.graus = graus;
    p.pos   = 0;
    p.erro  = false;
    double val = p.parseExpr();
    ok = !p.erro;
    return val;
}

// ─────────────────────────────────────────────
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->edt_calc->setReadOnly(true);
    ui->edt_calc->setAlignment(Qt::AlignRight);
    ui->edt_calc->setPlaceholderText("0");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::appendToExpr(const QString &texto)
{
    expressao += texto;
    ui->edt_calc->setText(expressao);
}

static bool terminaComOp(const QString &s)
{
    if (s.isEmpty()) return false;
    QChar c = s.back();
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void MainWindow::on_btn_0_clicked() { appendToExpr("0"); }
void MainWindow::on_btn_1_clicked() { appendToExpr("1"); }
void MainWindow::on_btn_2_clicked() { appendToExpr("2"); }
void MainWindow::on_btn_3_clicked() { appendToExpr("3"); }
void MainWindow::on_btn_4_clicked() { appendToExpr("4"); }
void MainWindow::on_btn_5_clicked() { appendToExpr("5"); }
void MainWindow::on_btn_6_clicked() { appendToExpr("6"); }
void MainWindow::on_btn_7_clicked() { appendToExpr("7"); }
void MainWindow::on_btn_8_clicked() { appendToExpr("8"); }
void MainWindow::on_btn_9_clicked() { appendToExpr("9"); }

void MainWindow::on_btn_mais_clicked()    { if (terminaComOp(expressao)) expressao.chop(1); appendToExpr("+"); }
void MainWindow::on_btn_menos_clicked()   { if (!expressao.isEmpty() && terminaComOp(expressao)) expressao.chop(1); appendToExpr("-"); }
void MainWindow::on_btn_vezes_clicked()   { if (terminaComOp(expressao)) expressao.chop(1); appendToExpr("*"); }
void MainWindow::on_btn_divisao_clicked() { if (terminaComOp(expressao)) expressao.chop(1); appendToExpr("/"); }

void MainWindow::on_btn_virgula_clicked()
{
    int pos = expressao.lastIndexOf(QRegularExpression("[+\\-*/()]"));
    QString parte = (pos == -1) ? expressao : expressao.mid(pos + 1);
    if (!parte.contains('.')) appendToExpr(".");
}

void MainWindow::on_btn_paraAbre_clicked()  { appendToExpr("("); }
void MainWindow::on_btn_paraFecha_clicked() { appendToExpr(")"); }

void MainWindow::on_btn_apagaTudo_clicked()
{
    expressao.clear();
    ui->edt_calc->clear();
    ui->edt_calc->setPlaceholderText("0");
}

void MainWindow::on_pushButton_29_clicked()
{
    if (terminaComOp(expressao)) expressao.chop(1);
    appendToExpr("/100");
}

void MainWindow::on_btn_igual_clicked()
{
    if (expressao.isEmpty()) return;

    QString expr = expressao;
    QRegularExpression fatRe("(\\d+)!");
    QRegularExpressionMatchIterator it = fatRe.globalMatch(expr);
    QList<QRegularExpressionMatch> matches;
    while (it.hasNext()) matches.prepend(it.next());
    for (auto &m : matches)
        expr.replace(m.capturedStart(), m.capturedLength(),
                     QString("fat(%1)").arg(m.captured(1)));

    bool ok = false;
    double val = avaliar(expr, modoGraus, ok);

    if (!ok || qIsNaN(val)) { ui->edt_calc->setText("Erro");     expressao.clear(); return; }
    if (qIsInf(val))        { ui->edt_calc->setText("Infinito"); expressao.clear(); return; }

    QString res = QString::number(val, 'g', 12);
    ui->edt_calc->setText(res);
    ultimoResultado = val;
    expressao = res;
}

void MainWindow::on_pushButton_24_clicked()
{
    modoGraus = true;
    ui->pushButton_24->setStyleSheet("font-weight:bold;color:green;");
    ui->pushButton_25->setStyleSheet("");
}

void MainWindow::on_pushButton_25_clicked()
{
    modoGraus = false;
    ui->pushButton_25->setStyleSheet("font-weight:bold;color:green;");
    ui->pushButton_24->setStyleSheet("");
}

void MainWindow::on_pushButton_26_clicked() { appendToExpr("!"); }

void MainWindow::on_pushButton_14_clicked()
{
    modoInv = !modoInv;
    if (modoInv) {
        ui->pushButton_14->setStyleSheet("font-weight:bold;color:orange;");
        ui->pushButton_15->setText("asin");
        ui->pushButton_12->setText("acos");
        ui->pushButton_11->setText("atan");
    } else {
        ui->pushButton_14->setStyleSheet("");
        ui->pushButton_15->setText("sin");
        ui->pushButton_12->setText("cos");
        ui->pushButton_11->setText("tan");
    }
}

void MainWindow::on_pushButton_15_clicked() { appendToExpr(modoInv ? "asin(" : "sin("); }
void MainWindow::on_pushButton_12_clicked() { appendToExpr(modoInv ? "acos(" : "cos("); }
void MainWindow::on_pushButton_11_clicked() { appendToExpr(modoInv ? "atan(" : "tan("); }
void MainWindow::on_pushButton_16_clicked() { appendToExpr("ln("); }
void MainWindow::on_pushButton_17_clicked() { appendToExpr("log("); }
void MainWindow::on_pushButton_13_clicked() { appendToExpr("pi"); }
void MainWindow::on_pushButton_10_clicked() { appendToExpr("e"); }
void MainWindow::on_pushButton_18_clicked() { appendToExpr("sqrt("); }
void MainWindow::on_pushButton_30_clicked() { appendToExpr(QString::number(ultimoResultado, 'g', 12)); }
void MainWindow::on_pushButton_31_clicked() { appendToExpr("*10^("); }
void MainWindow::on_pushButton_32_clicked() { appendToExpr("^"); }
