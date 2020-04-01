#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
//#include <MyHashTable.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_init_button_clicked();

    void on_random_button_clicked();

    void on_draw_button_clicked();

    void on_add_button_clicked();

    void on_find_button_clicked();

    void on_delete_button_clicked();

    void on_task_button_clicked();

    void on_delete_all_button_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
