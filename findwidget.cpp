#include "findwidget.h"
#include <QMessageBox>
#include <QFont>
#include <QPushButton>
#include <QSqlQuery>

FindWidget::FindWidget(QWidget *parent) : QWidget(parent)
{
    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    setWindowTitle("查找");
    setFixedSize(700, 600);

    QLabel *name_label = new QLabel("姓名：");
    name_label->setFont(font);
    name_label->setFixedSize(80, 40);

    name_edit = new QLineEdit();
    name_edit->setFont(font);
    name_edit->setFixedSize(200, 40);

    QPushButton *confirm_btn = new QPushButton("确定", this);
    confirm_btn->setFixedSize(80, 40);
    confirm_btn->setFont(font);
    connect(confirm_btn, &QPushButton::clicked, this, &FindWidget::confirmBtn_click);

    QHBoxLayout *name_layout = new QHBoxLayout();
    name_layout->setMargin(0);
    name_layout->setSpacing(0);
    name_layout->addStretch(1);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    name_layout->addSpacing(20);
    name_layout->addWidget(confirm_btn);
    name_layout->addSpacing(110);

    QLabel *sex_label = new QLabel("性别：");
    sex_label->setFont(font);
    sex_label->setFixedSize(80, 40);

    sex_edit = new QComboBox();
    sex_edit->addItem("男");
    sex_edit->addItem("女");
    sex_edit->setFont(font);
    sex_edit->setFixedSize(200, 40);

    QHBoxLayout *sex_layout = new QHBoxLayout();
    sex_layout->setMargin(0);
    sex_layout->setSpacing(0);
    sex_layout->addStretch(1);
    sex_layout->addWidget(sex_label);
    sex_layout->addWidget(sex_edit);
    sex_layout->addStretch(1);

    QLabel *age_label = new QLabel("年龄：");
    age_label->setFont(font);
    age_label->setFixedSize(80, 40);

    age_edit = new QLineEdit();
    age_edit->setFont(font);
    age_edit->setFixedSize(200, 40);

    QHBoxLayout *age_layout = new QHBoxLayout();
    age_layout->setMargin(0);
    age_layout->setSpacing(0);
    age_layout->addStretch(1);
    age_layout->addWidget(age_label);
    age_layout->addWidget(age_edit);
    age_layout->addStretch(1);


    QLabel *id_label = new QLabel("学号：");
    id_label->setFont(font);
    id_label->setFixedSize(80, 40);

    id_edit = new QLineEdit();
    id_edit->setFont(font);
    id_edit->setFixedSize(200, 40);

    QHBoxLayout *id_layout = new QHBoxLayout();
    id_layout->setMargin(0);
    id_layout->setSpacing(0);
    id_layout->addStretch(1);
    id_layout->addWidget(id_label);
    id_layout->addWidget(id_edit);
    id_layout->addStretch(1);

    QLabel *phone_label = new QLabel("电话：");
    phone_label->setFont(font);
    phone_label->setFixedSize(80, 40);

    phone_edit = new QLineEdit();
    phone_edit->setFont(font);
    phone_edit->setFixedSize(200, 40);

    QHBoxLayout *phone_layout = new QHBoxLayout();
    phone_layout->setMargin(0);
    phone_layout->setSpacing(0);
    phone_layout->addStretch(1);
    phone_layout->addWidget(phone_label);
    phone_layout->addWidget(phone_edit);
    phone_layout->addStretch(1);

    QLabel *address_label = new QLabel("住址：");
    address_label->setFont(font);
    address_label->setFixedSize(80, 40);

    address_edit = new QLineEdit();
    address_edit->setFont(font);
    address_edit->setFixedSize(200, 40);

    QHBoxLayout *address_layout = new QHBoxLayout();
    address_layout->setMargin(0);
    address_layout->setSpacing(0);
    address_layout->addStretch(1);
    address_layout->addWidget(address_label);
    address_layout->addWidget(address_edit);
    address_layout->addStretch(1);

    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->setMargin(0);
    mainlayout->setSpacing(0);
    mainlayout->addLayout(name_layout);
    mainlayout->addLayout(sex_layout);
    mainlayout->addLayout(age_layout);
    mainlayout->addLayout(id_layout);
    mainlayout->addLayout(phone_layout);
    mainlayout->addLayout(address_layout);
    mainlayout->addSpacing(10);
    this->setLayout(mainlayout);

    QPushButton *return_btn = new QPushButton("返回", this);
    return_btn->setGeometry(this->width()-110, this->height()-50, 100, 50);
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &FindWidget::returnBtn_click);
}

FindWidget::~FindWidget()
{

}

void FindWidget::confirmBtn_click()
{
    QString select = QString("select * from message");
    QSqlQuery query;
    query.exec(select);
    while(query.next())
    {
        if(query.value(1).toInt()) sex_edit->setCurrentText("男");
        else sex_edit->setCurrentText("女");
        id_edit->setText(query.value(2).toString());
        age_edit->setText(query.value(3).toString());
        phone_edit->setText(query.value(4).toString());
        address_edit->setText(query.value(5).toString());
        break;
    }
}


void FindWidget::returnBtn_click()
{
    MainWindow *m = new MainWindow();
    m->show();
    this->close();
}

