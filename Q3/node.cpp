#include "node.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

node::node(int k,int v)
{
    //cout<<"haha2\n";
    kv_pair=new key_val(k,v);
    parent=NULL;
    left=NULL;
    right=NULL;
    //height=0;
    color=0;          // 0 means red
    //ctor
}

int node::getcolor()
{
    return color;
}

void node::setcolor(int c)
{
    color=c;
}

node* node::leftn()
{
    return left;
}

node* node::rightn()
{
    return right;
}

node* node::parentn()
{
    return parent;
}

void node::newleft(node* n)
{
    left=n;
}

void node::newright(node* n)
{
    right=n;
}

void node::newparent(node* n)
{
    parent=n;
}

/*
int node::getheight()
{
    return height;
}

void node::setheight(int h)
{
    height=h;
}
*/

int node::getvalue()
{
    return kv_pair->getval();
}

int node::getkey()
{
    return kv_pair->getk();
}

void node::setvalue(int v)
{
    kv_pair->setval(v);
}

void node::setkey(int k)
{
    kv_pair->setk(k);
}

node::~node()
{
    //dtor
}
