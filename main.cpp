#include "mainwindow.h"
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDatabase>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //添加MYSQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //数据库对象
    //设置数据库
    db.setDatabaseName("./message.db");
    //打开数据库
    if( !db.open() )
    {
        //数据库打开失败
        qDebug("db open fail");
        return -1;
    }
    QSqlQuery query;
    query.exec("create table message(name QString, sex bool, \
                                    id int, age int, phone QString, address QString)");


    return a.exec();
}
