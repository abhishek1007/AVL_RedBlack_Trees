#ifndef KEY_VAL_H
#define KEY_VAL_H
#include <iostream>
#include <stdlib.h>

using namespace std;


class key_val
{
    public:
        key_val(int,int);
        int getval();
        int getk();
        void setval(int);
        void setk(int);
        virtual ~key_val();
    protected:
    private:
        int key;
        int value;
};

#endif // KEY_VAL_H
