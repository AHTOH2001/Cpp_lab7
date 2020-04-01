#ifndef DEMONSTRATIONCLASS_H
#define DEMONSTRATIONCLASS_H

#include "mainwindow.h"
#include <MyHashTable.h>
#include <QMessageBox>
#include <QTime>
class DemonstrationClass
{
public:
    DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent);

    ~DemonstrationClass();

    void on_init_button_clicked();

    void on_random_button_clicked();

    void on_draw_button_clicked();

    void on_add_button_clicked();

    void on_find_button_clicked();

    void on_delete_button_clicked();

    void on_task_button_clicked();

    void on_delete_all_button_clicked();

    MyHashTable<QString>* hash;
private:
    Ui::MainWindow* ui;
    MainWindow *parent;


};

#endif // DEMONSTRATIONCLASS_H
