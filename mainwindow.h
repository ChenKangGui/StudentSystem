#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "addwidget.h"
#include "showwidget.h"
#include "deletewidget.h"
#include "findwidget.h"
#include "changewidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addBtn_click();
    void changeBtn_click();
    void deleteBtn_click();
    void findBtn_click();
    void showBtn_click();
};

#endif // MAINWINDOW_H
