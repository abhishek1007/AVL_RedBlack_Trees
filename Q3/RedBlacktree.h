#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "node.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;


class RedBlacktree
{
    public:
        RedBlacktree();
        void insert(int,int);
        void remove(int);
        void search(int);
        int no_leaves();
        int tree_height();
        int tree_blackheight();
        vector<int> inorder(int,int);





        int leaves(node*);

        int height(node*);
        node* successor(node*);
        void rightrotate(node*);
        void leftrotate(node*);

        void doublered(node*);
        node* otherchild(node* p, node* n);
        void display();
        void disp(node*,int);
        void autocorrect(node*,node*);
        ///////////
        node* getroot();
        virtual ~RedBlacktree();
    protected:
    private:
        int siz;
        node* root;
};

#endif // REDBLACKTREE_H
