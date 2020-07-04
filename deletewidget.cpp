#include "deletewidget.h"
#include <QLabel>
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QMessageBox>

DeleteWidget::DeleteWidget(QWidget *parent) : QWidget(parent)
{
    QFont font;
    font.setPointSize(14);
    font.setBold(true);

    this->setParent(parent);
    setWindowTitle("删除");
    setFixedSize(400, 300);

    QLabel *name_label = new QLabel("姓名:");
    name_label->setFont(font);
    name_label->setFixedSize(80, 40);

    name_edit = new QLineEdit();
    name_edit->setFont(font);
    name_edit->setFixedSize(200, 40);

    QHBoxLayout *name_layout = new QHBoxLayout();
    name_layout->setMargin(0);
    name_layout->setSpacing(5);
    name_layout->addStretch(1);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    name_layout->addStretch(1);

    QPushButton *confirm_btn = new QPushButton("确定");
    confirm_btn->setFixedSize(80, 40);
    confirm_btn->setFont(font);
    connect(confirm_btn, &QPushButton::clicked, this, &DeleteWidget::confirmBtn_click);

    QPushButton *cancel_btn = new QPushButton("取消");
    cancel_btn->setFixedSize(80, 40);
    cancel_btn->setFont(font);
    connect(cancel_btn, &QPushButton::clicked, this, &DeleteWidget::cancleBtn_click);

    QHBoxLayout *btn_layout = new QHBoxLayout();
    btn_layout->setMargin(0);
    btn_layout->setSpacing(50);
    btn_layout->addStretch(1);
    btn_layout->addWidget(confirm_btn);
    btn_layout->addWidget(cancel_btn);
    btn_layout->addStretch(1);

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->setMargin(0);
    mainlayout->setSpacing(50);
    mainlayout->addStretch(1);
    mainlayout->addLayout(name_layout);
    mainlayout->addLayout(btn_layout);
    mainlayout->addStretch(1);
    this->setLayout(mainlayout);
}

DeleteWidget::~DeleteWidget()
{

}

void DeleteWidget::confirmBtn_click()
{
    QString name = name_edit->text();

    if(name.isEmpty())
    {
        QMessageBox::about(this, "tips", "输入不能为空");
        return ;
    }

    QString str = QString("DELETE FROM message WHERE  name = '%1'").arg(name);
    QSqlQuery query;
    query.exec(str);

    QMessageBox::about(this, "tips", "删除成功");
    this->close();

    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

void DeleteWidget::cancleBtn_click()
{
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}

