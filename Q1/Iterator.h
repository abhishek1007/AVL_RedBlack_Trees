#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include "AVLtree.h"
#include <stdlib.h>
class AVLtree;
class Iterator
{
    public:
        key_val operator *();
        bool operator ==(const Iterator &p)const;
        bool operator !=(const Iterator &p)const;
        Iterator operator ++();
        Iterator operator --();
        ~Iterator();
        friend class AVLtree;
    private:
        node *v;
        key_val *elem;
        AVLtree *t;
        Iterator(node *u,AVLtree* tt);


};

#endif // ITERATOR_H
