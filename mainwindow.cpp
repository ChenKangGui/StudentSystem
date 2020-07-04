#include "mainwindow.h"
#include <QFont>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFont font;
    font.setBold(true);
    font.setPointSize(18);

    setWindowTitle("学生信息管理系统");
    setFixedSize(700, 600);

    QLabel *title_label = new QLabel("学生信息管理系统", this);
    title_label->setGeometry(250, 50, 300, 50);
    title_label->setFont(font);

    font.setPointSize(12);
    QPushButton *add_btn = new QPushButton("添加", this);
    add_btn->setGeometry(300, 150, 100, 50);
    add_btn->setFont(font);
    connect(add_btn, &QPushButton::clicked, this, &MainWindow::addBtn_click);

    QPushButton *change_btn = new QPushButton("修改", this);
    change_btn->setGeometry(300, 220, 100, 50);
    change_btn->setFont(font);
    connect(change_btn, &QPushButton::clicked, this, &MainWindow::changeBtn_click);

    QPushButton *delete_btn = new QPushButton("删除", this);
    delete_btn->setGeometry(300, 290, 100, 50);
    delete_btn->setFont(font);
    connect(delete_btn, &QPushButton::clicked, this, &MainWindow::deleteBtn_click);

    QPushButton *find_btn = new QPushButton("查找", this);
    find_btn->setGeometry(300, 360, 100, 50);
    find_btn->setFont(font);
    connect(find_btn, &QPushButton::clicked, this, &MainWindow::findBtn_click);

    QPushButton *show_btn = new QPushButton("查看", this);
    show_btn->setGeometry(300, 430, 100, 50);
    show_btn->setFont(font);
    connect(show_btn, &QPushButton::clicked, this, &MainWindow::showBtn_click);
}

MainWindow::~MainWindow()
{

}


void MainWindow::addBtn_click()
{
    this->close();
    AddWidget *addWidget = new AddWidget();
    addWidget->show();
}


void MainWindow::changeBtn_click()
{
    ChangeWidget *c = new ChangeWidget();
    c->show();
    this->close();
}


void MainWindow::showBtn_click()
{
    ShowWidget *w = new ShowWidget();
    this->close();
    w->show();
}

void MainWindow::findBtn_click()
{
    FindWidget *f = new FindWidget();
    f->show();
    this->close();
}


void MainWindow::deleteBtn_click()
{
    DeleteWidget *d = new DeleteWidget();
    d->show();
    this->close();
}
