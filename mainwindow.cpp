#include "mainwindow.h"
#include <demonstrationclass.h>
DemonstrationClass* demclass;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    demclass = new DemonstrationClass(ui,this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_init_button_clicked()
{
    demclass->on_init_button_clicked();
}

void MainWindow::on_random_button_clicked()
{
    demclass->on_random_button_clicked();
}

void MainWindow::on_draw_button_clicked()
{
    demclass->on_draw_button_clicked();
}

void MainWindow::on_add_button_clicked()
{
    demclass->on_add_button_clicked();
}

void MainWindow::on_find_button_clicked()
{
    demclass->on_find_button_clicked();
}

void MainWindow::on_delete_button_clicked()
{
    demclass->on_delete_button_clicked();
}

void MainWindow::on_task_button_clicked()
{
    demclass->on_task_button_clicked();
}

void MainWindow::on_delete_all_button_clicked()
{
    demclass->on_delete_all_button_clicked();
}
