#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
//#define NULL 0
#include <cstddef>
template <typename T>
class MyHashTable
{
public:
    struct node
    {
        int k;
        T data;
        node *next;
        node(int _k,T _data)
        {
            k = _k;
            data = _data;
            next = NULL;
        }
    };
    MyHashTable()
    {

    }
    int Encode (int x)
    {
        if (x%m<0) return x%m+m;
        else return x%m;
    }
    void Add(int k,T data)
    {
        try{
            Find(k);
        }
        catch(int)
        {
            node *Q = new node(k,data);
            Q->next = a[Encode(k)];
            a[Encode(k)] = Q;
            return;
        }
        throw (-1);
    }
    T Find(int k)
    {
        node *Q = a[Encode(k)];
        while (Q!=NULL)
        {
            if (Q->k==k) return (Q->data);
            Q=Q->next;
        }
        throw (-1);
    }
    void Delete(int k)
    {
        node *Q = a[Encode(k)];
        if (Q==NULL) throw (-1);
        if (Q->k==k)
            a[Encode(k)] = Q->next;
        else
            while (Q->next!=NULL)
            {
                if (Q->next->k==k)
                {
                    Q->next = Q->next->next;
                    return;
                }
                Q=Q->next;
            }
    }
    int m;
    node* a[100000] = {NULL};

private:


};

#endif // MYHASHTABLE_H
