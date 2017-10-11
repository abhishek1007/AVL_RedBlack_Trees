#include "Iterator.h"
#include <iostream>
#include <stdlib.h>

Iterator::Iterator(node* u,AVLtree* tt)
{
    v=u;
    t=tt;
    if(u!=NULL)
    {
        elem=new key_val(v->getkey(),v->getvalue());
    }
    else
    {
        elem=NULL;
    }
    //ctor
}

key_val Iterator::operator *()
{
    return *elem;
}

bool Iterator::operator ==(const Iterator &p)const
{
    return (v==p.v);
}

bool Iterator::operator !=(const Iterator &p)const
{
    return (v!=p.v);
}

Iterator Iterator::operator ++()
{
    if(v==NULL)
    {
        return t->end();
    }
    else
    {
        v=t->successor(v);
        if(v!=NULL)
        {
            elem->setk(v->getkey());
            elem->setval(v->getvalue());
            return *this;
        }
        else
        {
            return t->end();
        }
    }
}

Iterator Iterator::operator --()
{
    if(v==NULL)
    {
        return t->end();
    }
    else
    {
        v=t->predecessor(v);
        if(v!=NULL)
        {
            elem->setk(v->getkey());
            elem->setval(v->getvalue());
            return *this;
        }
        else
        {
            return t->end();
        }
    }
}


Iterator::~Iterator()
{
    //dtor
}

