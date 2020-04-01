#include "demonstrationclass.h"
#include <variant3.h>
Variant3* var3;
DemonstrationClass::DemonstrationClass(Ui::MainWindow* _ui,MainWindow *_parent)
{
    ui = _ui;
    parent = _parent;
    parent->setFixedSize(720,680);
    var3 = new Variant3(ui,this);
    ui->gridLayoutWidget_6->hide();
    ui->delete_all_button->hide();
    ui->draw_button->hide();
    ui->textBrowser->hide();
    QTime now = QTime::currentTime();
    srand(now.msec());
}

DemonstrationClass::~DemonstrationClass()
{

}

void DemonstrationClass::on_init_button_clicked()
{
    hash = new MyHashTable<QString>;
    hash->m = ui->init_line->text().toInt();
    ui->gridLayoutWidget_6->show();
}
QStringList str = {"суровый","важный","структурный","дипломатический","таможенный","глупый","доступный","огромный","промышленный","тогдашний","тепловой","студенческий"};
void DemonstrationClass::on_random_button_clicked()
{
    int L = ui->L_line->text().toInt();
    int R = ui->R_line->text().toInt();
    int N = ui->N_line->text().toInt();
    int err = 0;
    if (L>R || (R-L+1)<N)
    {
        QMessageBox::critical(parent," ","Error");
        return;
    }
    for (int i = 0;i<N;i++)
    {
        try
        {
            hash->Add((rand()*rand())%(R-L+1)+L,str[rand()%str.length()]);
            err = 0;
        }catch(int)
        {
            err++;
            i--;
        }
        if (err>1000) return;
    }
}
void DemonstrationClass::on_draw_button_clicked()
{
    ui->textBrowser->clear();
    QString s = "";
    for (int i = 0;i<hash->m;i++)
    {
        s+=QString::number(i)+": ";
        MyHashTable<QString>::node* Q = hash->a[i];
        while (Q!=NULL)
        {
            if (Q!=hash->a[i]) s+="-> ";
            s+="(" + QString::number(Q->k) + "," + Q->data + ") ";
            Q=Q->next;
        }
        s+='\n';
    }
    ui->textBrowser->setText(s);
}


void DemonstrationClass::on_add_button_clicked()
{
    try{
        hash->Add(ui->key_add->text().toInt(),ui->info_add->text());
        QMessageBox::information(parent,"Well done","Node added successfully");
    }
    catch(int)
    {
        QMessageBox::critical(parent," ","Error");
    }
}

void DemonstrationClass::on_find_button_clicked()
{
    try{
        QMessageBox::information(parent,"Well done",hash->Find(ui->key_find->text().toInt()));
    }catch(int)
    {
        QMessageBox::critical(parent," ","Error");
    }
}

void DemonstrationClass::on_delete_button_clicked()
{
    try{
        hash->Delete(ui->key_delete->text().toInt());
    }
    catch(int)
    {
        QMessageBox::critical(parent," ","Error");
    }
}

void DemonstrationClass::on_task_button_clicked()
{
    var3->on_task_button_clicked();
}

void DemonstrationClass::on_delete_all_button_clicked()
{
    hash = NULL;
    ui->gridLayoutWidget_6->hide();
    ui->textBrowser->clear();
}

