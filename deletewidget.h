#ifndef DELETEWIDGET_H
#define DELETEWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"
#include <QLineEdit>

class DeleteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DeleteWidget(QWidget *parent=0);
    ~DeleteWidget();

    QLineEdit *name_edit;
public slots:
    void confirmBtn_click();
    void cancleBtn_click();
};

#endif // DELETEWIDGET_H
