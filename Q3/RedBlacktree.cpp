#include "RedBlacktree.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

RedBlacktree::RedBlacktree()
{
    siz=0;
    root=NULL;
    //ctor
}

int RedBlacktree::leaves(node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    else if(n->leftn()==NULL && n->rightn()==NULL)
    {
        return 1;
    }
    else if(n->leftn()==NULL)
    {
        return leaves(n->rightn());
    }
    else if(n->rightn()==NULL)
    {
        return leaves(n->leftn());
    }
    else
    {
        return leaves(n->leftn())+leaves(n->rightn());
    }
}

int RedBlacktree::no_leaves()
{
    return leaves(root);
}

void RedBlacktree::rightrotate(node* u)
{
    
    node* v;
    v=u->leftn();
    node* T1;
    node* T2;
    node* T3;
    node* p;
    T1=v->leftn();
    T2=v->rightn();
    T3=u->rightn();
    p=u->parentn();
    if(T2!=NULL)
        T2->newparent(u);
    u->newleft(T2);
    v->newright(u);
    u->newparent(v);
    v->newparent(p);
    if(p!=NULL && p->leftn()==u)
    {
        p->newleft(v);
    }
    else if(p!=NULL && p->rightn()==u)
    {
        p->newright(v);
    }
    if(p==NULL)
    {
        root=v;
    }
    cout<<"Tree after right rotation at "<<u->getkey()<<":\n";
    display();
    cout<<"\n\n";
}

void RedBlacktree::leftrotate(node* u)
{
    node* v;
    v=u->rightn();
    node* T1;
    node* T2;
    node* T3;
    node* p;
    T1=u->leftn();
    T2=v->leftn();
    T3=v->rightn();
    p=u->parentn();
    if(T2!=NULL)
        T2->newparent(u);
    u->newright(T2);
    v->newleft(u);
    u->newparent(v);
    v->newparent(p);
    if(p!=NULL && p->leftn()==u)
    {
        p->newleft(v);
    }
    else if(p!=NULL && p->rightn()==u)
    {
        p->newright(v);
    }
    if(p==NULL)
    {
        root=v;
    }
    cout<<"Tree after left rotation at "<<u->getkey()<<":\n";
    display();
    cout<<"\n\n";
}


node* RedBlacktree::getroot()
{
    return root;
}

void RedBlacktree::display()
{
    disp(root,1);
}

void RedBlacktree::disp(node *ptr, int level)
{
    /////////////
    int i;

    if (ptr!=NULL)
    {
       
        disp(ptr->rightn(), level + 1);
        cout<<("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<< (ptr->getkey());
        if(ptr->getcolor()==1)
        {
            cout<<"(B)  ";
        }
        else if(ptr->getcolor()==0)
        {
            cout<<"(R)  ";
        }
       
        disp(ptr->leftn(), level + 1);
    }
    else if(ptr==NULL && level==1)
    {
        cout<<"NULL\n";
    }
}

void RedBlacktree::insert(int k,int v)
{
    node* cur;
    cur=root;
    if(siz==0)
    {

        root=new node(k,v);
        root->setcolor(1);
        siz++;
	cout<<"Tree after insertion of ("<<k<<","<<v<<") :\n";
    	display();
        cout<<"\n\n";
        // height assigned 0 automatically
    }
    else
    {
    
        node* prev;
        prev=root;
        while(cur!=NULL && (cur->getkey())!=k)
        {
            prev=cur;
            if(k<(cur->getkey()))
            {
                cur=cur->leftn();
            
            }
            else if(k>(cur->getkey()))
            {
                cur=cur->rightn();
           
            }
        }
        if(cur!=NULL && cur->getkey()==k)
        {
     
            cur->setvalue(v);
        }
        else if(cur==NULL)
        {
            siz++;
      
            cur=new node(k,v);
            cur->newparent(prev);
            if(prev->getkey()<k)
            {
                prev->newright(cur);
            }
            else if(prev->getkey()>k)
            {
                
                prev->newleft(cur);
            }
		
	cout<<"Tree after insertion of ("<<k<<","<<v<<") is given above\n";
    	display();
        cout<<"\n\n";
            if(prev->getcolor()==0)
            {
                doublered(cur);
            }
        }

    }

    // check when to increment size
    //siz++;
}

void RedBlacktree::doublered(node* n)
{
    node* p;
    node* g;
    p=n->parentn();
    if(p==NULL)
    {
        n->setcolor(1);
    }
    else if(otherchild(p->parentn(),p)==NULL || (otherchild(p->parentn(),p))->getcolor()==1)
    {
        
        g=p->parentn();
        if(g->leftn()==p && p->leftn()==n)
        {
            rightrotate(g);
            g->setcolor(0);
            p->setcolor(1);
        }
        else if(g->rightn()==p && p->rightn()==n)
        {
            leftrotate(g);
            g->setcolor(0);
            p->setcolor(1);
        }
        else if(g->leftn()==p && p->rightn()==n)
        {
            leftrotate(p);
            rightrotate(g);
            g->setcolor(0);
            n->setcolor(1);

        }
        else if(g->rightn()==p && p->leftn()==n)
        {
            rightrotate(p);
            leftrotate(g);
            g->setcolor(0);
            n->setcolor(1);
        }
    }
    else if((otherchild(p->parentn(),p))->getcolor()==0)
    {
        
        g=p->parentn();
        otherchild(g,p)->setcolor(1);
        p->setcolor(1);
        g->setcolor(0);
        if(g->parentn()==NULL || (g->parentn())->getcolor()==0)
        {
            doublered(g);
        }
    }
}

node* RedBlacktree::otherchild(node* p, node* c)
{
    if(p->rightn()==c)
    {
        return p->leftn();
    }
    else if(p->leftn()==c)
    {
        return p->rightn();
    }
}


void RedBlacktree::search(int k)
{
    node* cur;
    cur=root;
    if(siz==0)
    {
        cout<<"\nTree is empty\n";
    }
    else
    {
        while(cur!=NULL && cur->getkey()!=k)
        {
            if(cur->getkey()>k)
            {
                cur=cur->leftn();
            }
            else if(cur->getkey()<k)
            {
                cur=cur->rightn();
            }
        }
        if(cur!=NULL)
        {
            cout<<"\nThe node with key "<<k<<" is present in the tree and the corresponding value is "<<cur->getvalue()<<"\n";
        }
        else
        {
            cout<<"\nNo node with key "<<k<<" found\n";
        }
    }
}

int RedBlacktree::height(node* n)
{
    if(n==NULL)
    {
        return -1;
    }
    else if(n->leftn()==NULL && n->rightn()==NULL)
    {
        return 0;
    }
    else if(n->leftn()==NULL)
    {
        return height(n->rightn())+1;
    }
    else if(n->rightn()==NULL)
    {
        return height(n->leftn())+1;
    }
    else
    {
        return (max(height(n->leftn()),height(n->rightn()))+1);
    }
}

int RedBlacktree::tree_height()
{
    return height(root);
}

vector<int> RedBlacktree::inorder(int a,int b)
{
    vector<int> v;
    node* n;
    node* prev;
    n=root;
    if(n!=NULL)
    {
        prev=n;
        while(n!=NULL && n->getkey()!=a)
        {
            prev=n;
            if(n->getkey()>a)
            {
                n=n->leftn();
            }
            else if(n->getkey()<a)
            {
                n=n->rightn();
            }
        }
        if(n==NULL)
        {
            n=prev;
            if(n->getkey()<a)
            {
                n=successor(n);
            }
        }
        else if(n->getkey()==a)
        {
            // do nothing
        }
        while(n!=NULL && n->getkey()<=b)
        {
            v.push_back(n->getkey());
            n=successor(n);
        }
    }
    return v;
}

int RedBlacktree::tree_blackheight()
{
    node* n;
    n=root;
    int k=1;
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        while(n->leftn()!=NULL)
        {
            n=n->leftn();
            if(n->getcolor()==1)
            {
                k++;
            }
        }
        return k;
    }

}

void RedBlacktree::remove(int k)
{
    node* cur;
    cur=root;
    while(cur!=NULL && cur->getkey()!=k)
    {
        if(cur->getkey()<k)
        {
            cur=cur->rightn();
        }
        else if(cur->getkey()>k)
        {
            cur=cur->leftn();
        }
    }
    if(cur!=NULL && cur->getkey()==k)
    {
        cout<<"Deleting: "<<k<<"\n";
        ////// decrementing size
        if(cur->leftn()==NULL && cur->rightn()==NULL)
        {
            if(cur->getcolor()==0)
            {
                node* p;
                p=cur->parentn();
                if(p->leftn()==cur)
                {
                    p->newleft(NULL);
                }
                else if(p->rightn()==cur)
                {
                    p->newright(NULL);
                }
                delete cur;
            }
            else if(cur->getcolor()==1)
            {
                
                if(siz==1)
                {
                    
                    delete cur;
                    root=NULL;
                }
                else
                {
                    node* p;
                    node* sib;
                    p=cur->parentn();
                    sib=otherchild(p,cur);
                    if(p->leftn()==cur)
                    {
                        p->newleft(NULL);
                        cout<<"left\n";
                    }
                    else if(p->rightn()==cur)
                    {
                        p->newright(NULL);
                        cout<<"right\n";
                    }
                   
                    delete cur;
                    autocorrect(p,sib);
                }
            }
        }
        else if((cur->leftn()==NULL || cur->rightn()==NULL) && (cur->leftn()!=NULL || cur->rightn()!=NULL))
        {
            
            node* p;
            node* c;
            if(cur->leftn()==NULL)
            {
                c=cur->rightn();
            }
            else
            {
                c=cur->leftn();
            }
            p=cur->parentn();
            c->newparent(p);
            if(p!=NULL)
            {
                if(p->leftn()==cur)
                {
                    p->newleft(c);
                }
                else if(p->rightn()==cur)
                {
                    p->newright(c);
                }
            }
            else
            {
                root=c;
            }
            c->setcolor(1);
            delete cur;
        }
        else               // both left child and right child not NULL
        {
           
            node* suc;
            suc=successor(cur);
            cur->setkey(suc->getkey());
            cur->setvalue(suc->getvalue());
            if(suc->rightn()==NULL)
            {
                if(suc->getcolor()==0)
                {
                    node* p;
                    p=suc->parentn();
                    if(p->leftn()==suc)
                    {
                        p->newleft(NULL);
                    }
                    else if(p->rightn()==suc)
                    {
                        p->newright(NULL);
                    }
                    delete suc;
                }
                else if(suc->getcolor()==1)
                {
                   
                    node* p;
                    node* sib;
                    p=suc->parentn();
                    sib=otherchild(p,suc);
                    if(p->leftn()==suc)
                    {
                        p->newleft(NULL);
                    }
                    else if(p->rightn()==suc)
                    {
                        p->newright(NULL);
                    }
                    delete suc;
                    autocorrect(p,sib);
                }
            }
            else if(suc->rightn()!=NULL)
            {
               
                node* p;
                node* c;
                c=suc->rightn();
                p=suc->parentn();
                c->newparent(p);
                if(p->leftn()==suc)
                {
                    p->newleft(c);
                }
                else if(p->rightn()==suc)
                {
                    p->newright(c);
                }
                c->setcolor(1);
                delete suc;
            }
        }
        siz--;
    }
    if(cur==NULL)
    {
        // no match found to delete
    }
}

void RedBlacktree::autocorrect(node* p,node* sib)
{
    node* a;
    node* b;
    a=p;
    b=sib;
    if(a!=NULL)
    {
        if(a->leftn()==b)
        {
            if(a->getcolor()==0)  ///// a is red ->  b is automatically black
            {
                node* c1;
                node* c2;
                c1=b->leftn();
                c2=b->rightn();
                if((c1==NULL || c1->getcolor()==1) && (c2==NULL || c2->getcolor()==1))
                {
                    a->setcolor(1);
                    b->setcolor(0);
                }
                else if(c1!=NULL && c1->getcolor()==0)
                {
                    a->setcolor(1);
                    b->setcolor(0);
                    c1->setcolor(1);
                    rightrotate(a);
                }
                else if(c2!=NULL && c2->getcolor()==0)
                {
                    a->setcolor(1);
                    leftrotate(b);
                    rightrotate(a);
                }
            }
            else if(a->getcolor()==1)
            {
                if(b->getcolor()==0)
                {
                    /////////////////////////////////////////////////////////////

                    node* c;
                    node* d1;
                    node* d2;
                    c=b->rightn();
                    d1=c->leftn();
                    d2=c->rightn();
                    if(d1!=NULL && d1->getcolor()==0)
                    {
                        leftrotate(b);
                        rightrotate(a);
                        d1->setcolor(1);
                    }
                    else if(d2!=NULL && d2->getcolor()==0)
                    {
                        leftrotate(c);
                        leftrotate(b);
                        rightrotate(a);
                        d2->setcolor(1);
                    }
                    else
                    {
                        rightrotate(a);
                        b->setcolor(1);
                        c->setcolor(0);
                        //////////////////////////////
                    }
                }
                else if(b->getcolor()==1)
                {
                    node* c1;
                    node* c2;
                    c1=b->leftn();
                    c2=b->rightn();
                    if(c1!=NULL && c1->getcolor()==0)
                    {
                        rightrotate(a);
                        c1->setcolor(1);
                    }
                    else if(c2!=NULL && c2->getcolor()==0)
                    {
                        leftrotate(b);
                        rightrotate(a);
                        c2->setcolor(1);
                    }
                    else
                    {
                        b->setcolor(0);
                        node* s;
                        node* par;
                        s=NULL;
                        par=a->parentn();
                        if(par!=NULL)
                        {
                            s=otherchild(par,a);
                        }
                        autocorrect(par,s);
                    }
                }
            }
        }
        else if(a->rightn()==b)
        {
            
            if(a->getcolor()==0)  ///// a is red ->  b is automatically black
            {
                node* c1;
                node* c2;
                c1=b->leftn();
                c2=b->rightn();
                if((c1==NULL || c1->getcolor()==1) && (c2==NULL || c2->getcolor()==1))
                {
                    a->setcolor(1);
                    b->setcolor(0);
                }
                else if(c2!=NULL && c2->getcolor()==0)
                {
                    a->setcolor(1);
                    b->setcolor(0);
                    c2->setcolor(1);
                    leftrotate(a);
                }
                else if(c1!=NULL && c1->getcolor()==0)
                {
                    a->setcolor(1);
                    rightrotate(b);
                    leftrotate(a);
                }
            }
            else if(a->getcolor()==1)
            {
                if(b->getcolor()==0)
                {
                    /////////////////////////////////////////////////////////////

                    node* c;
                    node* d1;
                    node* d2;
                    c=b->leftn();
                    d1=c->leftn();
                    d2=c->rightn();
                    if(d2!=NULL && d2->getcolor()==0)
                    {
                        rightrotate(b);
                        leftrotate(a);
                        d2->setcolor(1);
                    }
                    else if(d1!=NULL && d1->getcolor()==0)
                    {
                        rightrotate(c);
                        rightrotate(b);
                        leftrotate(a);
                        d1->setcolor(1);
                    }
                    else
                    {
                        leftrotate(a);
                        b->setcolor(1);
                        c->setcolor(0);
                        //////////////////////////////
                    }
                }
                else if(b->getcolor()==1)
                {
                    node* c1;
                    node* c2;
                    c1=b->leftn();
                    c2=b->rightn();
                    if(c2!=NULL && c2->getcolor()==0)
                    {
                        leftrotate(a);
                        c2->setcolor(1);
                    }
                    else if(c1!=NULL && c1->getcolor()==0)
                    {
                        rightrotate(b);
                        leftrotate(a);
                        c1->setcolor(1);
                    }
                    else
                    {
                        b->setcolor(0);
                        node* s;
                        node* par;
                        s=NULL;
                        par=a->parentn();
                        if(par!=NULL)
                        {
                            s=otherchild(par,a);
                        }
                        autocorrect(par,s);
                    }
                }
            }
        }
    }
}



node* RedBlacktree::successor(node* n)
{
    node* cur;
    node* prev;
    cur=n;
    if(cur->rightn()!=NULL)
    {
        cur=cur->rightn();
        while(cur->leftn()!=NULL)
        {
            cur=cur->leftn();
        }
        return cur;
    }
    else
    {
        prev=cur;
        cur=cur->parentn();
        while(cur!=NULL && cur->leftn()!=prev)
        {
            prev=cur;
            cur=cur->parentn();
        }
        if(cur!=NULL)
        {
            return cur;
        }
        else
        {
            // no successor
        }
    }
}


RedBlacktree::~RedBlacktree()
{
    //dtor
}
