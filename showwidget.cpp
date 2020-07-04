#include "showwidget.h"
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QHeaderView>
#include <QFont>
#include <QDebug>

ShowWidget::ShowWidget(QWidget *parent) : QWidget(parent)
{    
    //定义item
    QStandardItem* item = 0;
    QString name, id, phone, address, sex;
    int tmp, age, i=0;
    QFont font;
    font.setBold(true);
    font.setPointSize(14);

    setWindowTitle("显示");
    setFixedSize(700, 600);

    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("姓名,性别,学号,年龄,电话,住址").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    QString select = QString("select * from message");
    QSqlQuery query;
    query.exec(select);
    while(query.next())
    {
        name    = query.value(0).toString();
        tmp     = query.value(1).toInt();
        id      = query.value(2).toString();
        age     = query.value(3).toInt();
        phone   = query.value(4).toString();
        address = query.value(5).toString();

        if(tmp) sex = "男";
        else    sex = "女";

        item = new QStandardItem(name);
        model->setItem(i,0,item);
        item = new QStandardItem(sex);
        model->setItem(i,1,item);
        item = new QStandardItem(id);
        model->setItem(i,2,item);
        item = new QStandardItem(QString("%1").arg(age));
        model->setItem(i,3,item);
        item = new QStandardItem(phone);
        model->setItem(i,4,item);
        item = new QStandardItem(address);
        model->setItem(i,5,item);
        i++;
    }

    if(i<17)
    {
        for( ;i < 17;i++)
        {
            item = new QStandardItem(QString(""));
            model->setItem(i,0,item);
            item = new QStandardItem(QString(""));
            model->setItem(i,1,item);
            item = new QStandardItem(QString(""));
            model->setItem(i,2,item);
            item = new QStandardItem(QString(""));
            model->setItem(i,3,item);
            item = new QStandardItem(QString(""));
            model->setItem(i,4,item);
            item = new QStandardItem(QString(""));
            model->setItem(i,5,item);
        }
    }

    tableView = new QTableView(this);
    tableView->setGeometry(0, 0, 700, 537);
    tableView->setShowGrid(true);
    tableView->setGridStyle(Qt::SolidLine);
    tableView->setModel(model);
//    tableView->verticalHeader()->setVisible(false);  // 隐藏行号
    // tableView->setSortingEnabled(true);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //select a line
    tableView->horizontalHeader()->setHighlightSections(false);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setStyleSheet("QHeaderView::section { background-color:green; color:white};");

    QPushButton *return_btn = new QPushButton("返回", this);
    return_btn->setGeometry(600, 550, 80, 45);
    return_btn->setFont(font);
    connect(return_btn, &QPushButton::clicked, this, &ShowWidget::returnBtn_click);

    QPushButton *save_btn = new QPushButton("保存", this);
    save_btn->setGeometry(300, 550, 80, 45);
    save_btn->setFont(font);
    connect(save_btn, &QPushButton::clicked, this, &ShowWidget::saveBtn_click);
}

ShowWidget::~ShowWidget()
{

}

void ShowWidget::returnBtn_click()
{
    MainWindow *w = new MainWindow();
    this->close();
    w->show();
}

void ShowWidget::saveBtn_click()
{
    QString name, tmp, id, phone, address;
    bool sex, j;
    int age;
    QModelIndex index;
    int row = tableView->model()->rowCount();
    int col = tableView->model()->columnCount();

    for(int i=0; i<row; i++)
    {
        j = 0;

        index = tableView->model()->index(i, j);
        name = tableView->model()->data(index).toString();

        j++;
        index = tableView->model()->index(i, j);
        tmp = tableView->model()->data(index).toString();
        if(tmp == "男") sex = true;
        else  sex = false;

        j++;
        index = tableView->model()->index(i, j);
        id = tableView->model()->data(index).toString();

        j++;
        index = tableView->model()->index(i, j);
        age = tableView->model()->data(index).toInt();

        j++;
        index = tableView->model()->index(i, j);
        phone = tableView->model()->data(index).toString();

        j++;
        index = tableView->model()->index(i, j);
        address = tableView->model()->data(index).toString();

        if(!name.isEmpty())
        {
            QSqlQuery query;
            query.clear();
            query.exec("create table message(name QString, sex bool, \
                                            id int, age int, phone QString, address QString)");
            query.prepare("insert into message(name,sex,id,age,phone,address) values(?,?,?,?,?,?)");
            query.bindValue(0, name);
            query.bindValue(1, sex);
            query.bindValue(2, id);
            query.bindValue(3, age);
            query.bindValue(4, phone);
            query.bindValue(5, address);
            query.exec();
            QMessageBox::about(this, "tips","保存成功");
        }
    }
}


