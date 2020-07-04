#ifndef CHANGEWIDGET_H
#define CHANGEWIDGET_H

#include <QMessageBox>
#include <QFont>
#include <QPushButton>
#include <QSqlQuery>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include "mainwindow.h"

class ChangeWidget : public QWidget
{
    Q_OBJECT
public:
    ChangeWidget(QWidget *parent=0);
    ~ChangeWidget();

    QComboBox *sex_edit;
    QLineEdit *name_edit;
    QLineEdit *age_edit;
    QLineEdit *id_edit;
    QLineEdit *phone_edit;
    QLineEdit *address_edit;

public slots:
    void changeBtn_click();
    void confirmBtn_click();
    void cancleBtn_click();
};

#endif // CHANGEWIDGET_H
