#ifndef NODE_H
#define NODE_H
#include "key_val.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


class node
{
    public:
        node(int,int);
        node* leftn();
        node* rightn();
        node* parentn();
        void newleft(node*);
        void newright(node*);
        void newparent(node*);
        //int getheight();
        //void setheight(int);
        int getvalue();
        int getkey();
        void setvalue(int);
        void setkey(int);
        int getcolor();
        void setcolor(int);
        virtual ~node();
    protected:
    private:
        node* parent;
        node* left;
        node* right;
        key_val* kv_pair;
        //int height;
        int color;
};

#endif // NODE_H
