#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include "mainwindow.h"

class ShowWidget : public QWidget
{
    Q_OBJECT
public:
    ShowWidget(QWidget *parent=0);
    ~ShowWidget();

    QTableView *tableView;

public slots:
    void returnBtn_click();
    void saveBtn_click();
};

#endif // SHOWWIDGET_H
