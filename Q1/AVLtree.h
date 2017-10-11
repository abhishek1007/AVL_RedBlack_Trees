#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"
#include <iostream>
#include <stdlib.h>
#include "Iterator.h"

using namespace std;

class Iterator;
class AVLtree
{
    public:
        AVLtree();
        Iterator firstEntry();
        Iterator lastEntry();
        Iterator ceilingEntry(int);
        Iterator floorEntry(int);
        Iterator higherEntry(int);
        Iterator lowerEntry(int);
        int size();
        bool empty();
        Iterator find(int);
        Iterator put(int,int);
        void erase(int);
        void erase(Iterator);
        void display();

        Iterator end();

        ///////////
        virtual ~AVLtree();
        friend class Iterator;
    protected:
    private:

        int siz;
        node* root;

        //void trying();
        bool isbalanced(node*);
        node* successor(node*);
        node* predecessor(node*);
        void rightrotate(node*);
        void leftrotate(node*);
        int finalheight(node*);
        void balancetree(node*);
        node* selectmaxin(node*);
        void disp(node*,int);
};

#endif // AVLTREE_H
