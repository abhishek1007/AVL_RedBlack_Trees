#include "key_val.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

key_val::key_val(int k,int v)
{
    key=k;
    value=v;
    //ctor
}

void key_val::setval(int v)
{
    value=v;
}

void key_val::setk(int k)
{
    key=k;
}

int key_val::getval()
{
    return value;
}

int key_val::getk()
{
    return key;
}

key_val::~key_val()
{
    //dtor
}
