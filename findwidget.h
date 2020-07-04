#ifndef FINDWIDGET_H
#define FINDWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include "mainwindow.h"

class FindWidget : public QWidget
{
    Q_OBJECT
public:
    FindWidget(QWidget *parent=0);
    ~FindWidget();

    QComboBox *sex_edit;
    QLineEdit *name_edit;
    QLineEdit *age_edit;
    QLineEdit *id_edit;
    QLineEdit *phone_edit;
    QLineEdit *address_edit;

public slots:
    void confirmBtn_click();
    void returnBtn_click();
};

#endif // FINDWIDGET_H
