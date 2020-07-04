#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QSqlQuery>
#include <QComboBox>

class AddWidget : public QWidget
{
    Q_OBJECT
public:
    AddWidget(QWidget *parent=0);
    ~AddWidget();

    QComboBox *sex_edit;
    QLineEdit *name_edit;    
    QLineEdit *age_edit;
    QLineEdit *id_edit;
    QLineEdit *phone_edit;
    QLineEdit *address_edit;

public slots:
    void confirmBtn_click();
    void cancleBtn_click();

};

#endif // ADDWIDGET_H
