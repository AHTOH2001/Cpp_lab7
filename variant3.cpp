#include "variant3.h"
Ui::MainWindow* ui;
DemonstrationClass *parent;
Variant3::Variant3(Ui::MainWindow* _ui,DemonstrationClass *_parent)
{
    ui = _ui;
    parent = _parent;
}

void Variant3::on_task_button_clicked()
{

    for (int i = 0;i<parent->hash->m;i++)
    {
        MyHashTable<QString>::node* Q = parent->hash->a[i];
        while (Q!=NULL)
        {
            if (Q->k<0) parent->hash->Delete(Q->k);
            Q=Q->next;
        }
    }
}
