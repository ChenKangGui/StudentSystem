#include "addwidget.h"
#include <QMessageBox>
#include <QDebug>

AddWidget::AddWidget(QWidget *parent) : QWidget(parent)
{
    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    setWindowTitle("添加");
    setFixedSize(700, 600);

    QLabel *name_label = new QLabel("姓名：");
    name_label->setFont(font);
    name_label->setFixedSize(80, 40);

    name_edit = new QLineEdit();
    name_edit->setFont(font);
    name_edit->setFixedSize(200, 40);

    QHBoxLayout *name_layout = new QHBoxLayout();
    name_layout->setMargin(0);
    name_layout->setSpacing(0);
    name_layout->addStretch(1);
    name_layout->addWidget(name_label);
    name_layout->addWidget(name_edit);
    name_layout->addStretch(1);

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

    QPushButton *confirm_btn = new QPushButton("确定");
    confirm_btn->setFixedSize(80, 40);
    confirm_btn->setFont(font);
    connect(confirm_btn, &QPushButton::clicked, this, &AddWidget::confirmBtn_click);

    QPushButton *cancel_btn = new QPushButton("取消");
    cancel_btn->setFixedSize(80, 40);
    cancel_btn->setFont(font);
    connect(cancel_btn, &QPushButton::clicked, this, &AddWidget::cancleBtn_click);

    QHBoxLayout *btn_layout = new QHBoxLayout();
    btn_layout->setMargin(0);
    btn_layout->setSpacing(50);
    btn_layout->addStretch(1);
    btn_layout->addWidget(confirm_btn);
    btn_layout->addWidget(cancel_btn);
    btn_layout->addStretch(1);

    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->setMargin(0);
    mainlayout->setSpacing(0);
    mainlayout->addLayout(name_layout);
    mainlayout->addLayout(sex_layout);
    mainlayout->addLayout(age_layout);
    mainlayout->addLayout(id_layout);
    mainlayout->addLayout(phone_layout);
    mainlayout->addLayout(address_layout);
    mainlayout->addLayout(btn_layout);
    mainlayout->addSpacing(10);
    this->setLayout(mainlayout);
}

AddWidget::~AddWidget()
{

}

void AddWidget::confirmBtn_click()
{
    QString name = name_edit->text();
    QString sex = sex_edit->currentText();
    QString id = id_edit->text();
    QString age = age_edit->text();
    QString phone = phone_edit->text();
    QString address = address_edit->text();

    if(name.isEmpty() || sex.isEmpty() || id.isEmpty() || age.isEmpty() || phone.isEmpty() || address.isEmpty())
    {
        QMessageBox::about(this, "tips", "输入不能有空！！");
        return ;
    }

    QSqlQuery query;
    query.prepare("insert into message(name,sex,id,age,phone,address) values(?,?,?,?,?,?)");
    query.bindValue(0, name);
    if(sex == "男") query.bindValue(1, true);
    else    query.bindValue(1, false);
    query.bindValue(2, id);
    query.bindValue(3, age.toInt());
    query.bindValue(4, phone);
    query.bindValue(5, address);
    if(!query.exec())
    {
        qDebug() << "fail";
    }
    else
    {
        qDebug() << "success";
    }

    QMessageBox::about(this, "tips","添加成功");

    MainWindow *w = new MainWindow();
    this->close();
    w->show();
}

void AddWidget::cancleBtn_click()
{
    MainWindow *w = new MainWindow();
    this->close();
    w->show();
}
