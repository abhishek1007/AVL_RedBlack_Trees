#include "AVLtree.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

AVLtree::AVLtree()
{
    siz=0;
    root=NULL;
    //ctor
}

Iterator AVLtree::end()
{
    return(Iterator(NULL,this));
}

Iterator AVLtree::firstEntry()
{
    node* cur;
    cur=root;
    while(cur!=NULL && cur->leftn()!=NULL)
    {
        cur=cur->leftn();
    }
    if(cur!=NULL)
    {
        return(Iterator(cur,this));
    }
    else
    {
        return end();
    }
}

Iterator AVLtree::lastEntry()
{
    node* cur;
    cur=root;
    while(cur!=NULL && cur->rightn()!=NULL)
    {
        cur=cur->rightn();
    }
    if(cur!=NULL)
    {
        return(Iterator(cur,this));
    }
    else
    {
        return end();
    }
}

Iterator AVLtree::ceilingEntry(int k)
{
    node* cur;
    node* prev;
    cur=root;
    prev=cur;
    while(cur!=NULL && cur->getkey()!=k)
    {
        prev=cur;
        if(cur->getkey()>k)
        {
            cur=cur->leftn();
        }
        else if(cur->getkey()<k)
        {
            cur=cur->rightn();
        }
    }
    if(prev==NULL)
    {
        return end();
    }
    else if(cur!=NULL && cur->getkey()==k)
    {
        return(Iterator(cur,this));
    }
    else if(cur==NULL)
    {
        if(prev->getkey()>k)
        {
            return(Iterator(prev,this));
        }
        else
        {
            if(successor(prev)!=NULL)
            {
                return(Iterator(successor(prev),this));
            }
            else
            {
                return end();
            }
        }
    }
}

Iterator AVLtree::floorEntry(int k)
{
    node* cur;
    node* prev;
    cur=root;
    prev=cur;
    while(cur!=NULL && cur->getkey()!=k)
    {
        prev=cur;
        if(cur->getkey()>k)
        {
            cur=cur->leftn();
        }
        else if(cur->getkey()<k)
        {
            cur=cur->rightn();
        }
    }
    if(prev==NULL)
    {
        return end();
    }
    else if(cur!=NULL && cur->getkey()==k)
    {
        return(Iterator(cur,this));
    }
    else if(cur==NULL)
    {
        if(prev->getkey()<k)
        {
            return(Iterator(prev,this));
        }
        else
        {
            if(predecessor(prev)!=NULL)
            {
                return(Iterator(predecessor(prev),this));
            }
            else
            {
                return end();
            }
        }
    }
}

Iterator AVLtree::higherEntry(int k)
{
    node* cur;
    node* prev;
    cur=root;
    prev=cur;
    while(cur!=NULL && cur->getkey()!=k)
    {
        prev=cur;
        if(cur->getkey()>k)
        {
            cur=cur->leftn();
        }
        else if(cur->getkey()<k)
        {
            cur=cur->rightn();
        }
    }
    if(prev==NULL)
    {
        return end();
    }
    else if(cur!=NULL && cur->getkey()==k)
    {
        cur=successor(cur);
        return(Iterator(cur,this));
    }
    else if(cur==NULL)
    {
        if(prev->getkey()>k)
        {
            return(Iterator(prev,this));
        }
        else
        {
            if(successor(prev)!=NULL)
            {
                return(Iterator(successor(prev),this));
            }
            else
            {
                return end();
            }
        }
    }
}

Iterator AVLtree::lowerEntry(int k)
{
    node* cur;
    node* prev;
    cur=root;
    prev=cur;
    while(cur!=NULL && cur->getkey()!=k)
    {
        prev=cur;
        if(cur->getkey()>k)
        {
            cur=cur->leftn();
        }
        else if(cur->getkey()<k)
        {
            cur=cur->rightn();
        }
    }
    if(prev==NULL)
    {
        return end();
    }
    else if(cur!=NULL && cur->getkey()==k)
    {
        cur=predecessor(cur);
        return(Iterator(cur,this));
    }
    else if(cur==NULL)
    {
        if(prev->getkey()<k)
        {
            return(Iterator(prev,this));
        }
        else
        {
            if(predecessor(prev)!=NULL)
            {
                return(Iterator(predecessor(prev),this));
            }
            else
            {
                return end();
            }
        }
    }
}

int AVLtree::size()
{
    return siz;
}

bool AVLtree::empty()
{
    return(siz==0);
}

Iterator AVLtree::find(int k)
{
    node* cur;
    cur=root;
    if(cur==NULL)
    {
	return end();
    }
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
        return Iterator(cur,this);
    }
    else
    {
        return end();
    }
}

void AVLtree::display()
{
    disp(root,1);
}



void AVLtree::rightrotate(node* u)
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
    cout<<"\nTree after right rotation about "<<u->getkey()<<" is:\n\n";
    display();
    cout<<"\n";
}

void AVLtree::leftrotate(node* u)
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
    cout<<"\nTree after left rotation about "<<u->getkey()<<" is:\n\n";
    display();
    cout<<"\n";
}

int AVLtree::finalheight(node* n)
{
    node* l;
    node* r;
    l=n->leftn();
    r=n->rightn();
    if( (l==NULL && r==NULL) )
    {
        return 0;
    }
    else if( (l==NULL && r!=NULL) )
    {
        return (r->getheight())+1;
    }
    else if( (l!=NULL && r==NULL) )
    {
        return (l->getheight())+1;
    }
    else if( (l!=NULL && r!=NULL) )
    {
        return max( (r->getheight())+1 , (l->getheight())+1 );
    }
}


void AVLtree::disp(node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        disp(ptr->rightn(), level + 1);
        cout<<("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<< (ptr->getkey());//<<"  "<<ptr->getheight()<<"  ";
        disp(ptr->leftn(), level + 1);
    }
    else if(ptr==NULL && level==1)
    {
        cout<<"NULL\n";
    }
}

Iterator AVLtree::put(int k,int v)
{
    cout<<"\n\nInitial tree before insertion: \n";
    display();
    cout<<"\n";
    node* cur;
    cur=root;
    if(siz==0)
    {
        root=new node(k,v);
        siz++;
        cout<<"\nNew key value pair("<<k<<","<<v<<") has been inserted into the tree\nThe tree after insertion is:\n";
        display();
        return Iterator(root,this);
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
            cout<<"\nThe value of the node with key "<<k<<" has been modified to "<<v<<"\nThe new tree is: \n";
            display();
            cout<<"\n";
            return Iterator(cur,this);
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
            cout<<"\nNew node with key "<<k<<" and value "<<v<<" is inserted in the tree\n";
            cout<<"Tree after insertion: \n";
            display();
            cout<<"\n";
            node* x;
            node* y;
            node* z;
            x=y=z=NULL;
            x=cur;
            y=cur->parentn();
            z=(cur->parentn())->parentn();
            y->setheight((x->getheight())+1);

            while(z!=NULL)
            {

                z->setheight((y->getheight())+1);
                if(!isbalanced(z))
                {
                    break;
                }
                x=y;
                y=z;
                z=z->parentn();
            }
            if(z!=NULL)
            {
                if(z->leftn()==y && y->leftn()==x)
                {
                    rightrotate(z);
                    z->setheight(z->getheight()-2);
                }
                else if(z->rightn()==y && y->rightn()==x)
                {
                    leftrotate(z);
                    z->setheight(z->getheight()-2);
                }
                else if(z->leftn()==y && y->rightn()==x)
                {
                    leftrotate(y);
                    rightrotate(z);
                    x->setheight(x->getheight()+1);
                    y->setheight(y->getheight()-1);
                    z->setheight(z->getheight()-2);
                }
                else if(z->rightn()==y && y->leftn()==x)
                {
                    rightrotate(y);
                    leftrotate(z);
                    x->setheight(x->getheight()+1);
                    y->setheight(y->getheight()-1);
                    z->setheight(z->getheight()-2);
                }
            }
            return Iterator(cur,this);
            // if z==NULL then there is no need to do anything
        }
    }
}


bool AVLtree::isbalanced(node* n)
{
    int l,r;
    if(n->leftn()==NULL)
    {
        l=0;
    }
    else
    {
        l=(n->leftn())->getheight()+1;
    }
    if(n->rightn()==NULL)
    {
        r=0;
    }
    else
    {
        r=(n->rightn())->getheight()+1;
    }
    if(abs(l-r)>1)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void AVLtree::erase(int k)
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
        siz--;

        cout<<"\nTree before deletion:\n";
        display();
        cout<<"\n\nDeleting node with key "<<k<<"\n";
        if(cur->leftn()==NULL && cur->rightn()==NULL)
        {
            node* p;
            p=cur->parentn();
            if(p!=NULL)
            {
                if(p->leftn()==cur)
                {
                    p->newleft(NULL);
                }
                else if(p->rightn()==cur)
                {
                    p->newright(NULL);
                }
            }
            else
            {
                root=NULL;
            }
            delete cur;
            cur=NULL;
            cout<<"\nTree after deletion: \n";
            display();
            cout<<"\n";
            balancetree(p);
        }
        else if(cur->leftn()==NULL)
        {
            node* p;
            p=cur->parentn();
            if(p!=NULL)
            {
                if(p->leftn()==cur)
                {
                    p->newleft(cur->rightn());
                    (cur->rightn())->newparent(p);
                }
                else if(p->rightn()==cur)
                {
                    p->newright(cur->rightn());
                    (cur->rightn())->newparent(p);
                }
            }
            else
            {
                root=cur->rightn();
                root->newparent(NULL);
            }
            delete cur;
            cur=NULL;
            cout<<"\nTree after deletion: \n";
            display();
            cout<<"\n";
            balancetree(p);
        }
        else if(cur->rightn()==NULL)
        {
            node* p;
            p=cur->parentn();
            if(p!=NULL)
            {
                if(p->leftn()==cur)
                {
                    p->newleft(cur->leftn());
                    (cur->leftn())->newparent(p);
                }
                else if(p->rightn()==cur)
                {
                    p->newright(cur->leftn());
                    (cur->leftn())->newparent(p);
                }
            }
            else
            {
                root=cur->leftn();
                root->newparent(NULL);
            }
            delete cur;
            cur=NULL;
            cout<<"\nTree after deletion: \n";
            display();
            cout<<"\n";
            balancetree(p);
        }
        else if(cur->leftn()!=NULL && cur->rightn()!=NULL)
        {
            node* suc;
            suc=successor(cur);
            cur->setkey(suc->getkey());
            cur->setvalue(suc->getvalue());
            node* p;
            p=suc->parentn();
            if(suc->rightn()!=NULL)
            {
                if(p->rightn()==suc)
                {
                    p->newright(suc->rightn());
                    (suc->rightn())->newparent(p);
                }
                else if(p->leftn()==suc)
                {
                    p->newleft(suc->rightn());
                    (suc->rightn())->newparent(p);
                }
            }
            else
            {
                if(p->rightn()==suc)
                {
                    p->newright(NULL);
                }
                else if(p->leftn()==suc)
                {
                    p->newleft(NULL);
                }
            }
            delete suc;
            suc=NULL;
            cout<<"\nTree after deletion: \n";
            display();
            cout<<"\n";
            balancetree(p);
        }
    }
    else if(cur==NULL)
    {
        cout<<"\nNo node with key "<<k<<" found!\n";
        // no match found to delete
    }
}


void AVLtree::erase(Iterator ite)
{
    if(ite==end())
    {
        cout<<"\nERROR!    Iterator points to end\n";
    }
    else
    {
        int k;
        k=(*ite).getk();
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
            cout<<"\nTree before deletion:\n";
            display();

            siz--;
            cout<<"\n\nDeleting node with key "<<k<<"\n";
            if(cur->leftn()==NULL && cur->rightn()==NULL)
            {
                node* p;
                p=cur->parentn();
                if(p!=NULL)
                {
                    if(p->leftn()==cur)
                    {
                        p->newleft(NULL);
                    }
                    else if(p->rightn()==cur)
                    {
                        p->newright(NULL);
                    }
                }
                else
                {
                    root=NULL;
                }
                delete cur;
                cur=NULL;
                cout<<"\nTree after deletion: \n";
                display();
                cout<<"\n";
                balancetree(p);
            }
            else if(cur->leftn()==NULL)
            {
                node* p;
                p=cur->parentn();
                if(p!=NULL)
                {
                    if(p->leftn()==cur)
                    {
                        p->newleft(cur->rightn());
                        (cur->rightn())->newparent(p);
                    }
                    else if(p->rightn()==cur)
                    {
                        p->newright(cur->rightn());
                        (cur->rightn())->newparent(p);
                    }
                }
                else
                {
                    root=cur->rightn();
                    root->newparent(NULL);
                }
                delete cur;
                cur=NULL;
                cout<<"\nTree after deletion: \n";
                display();
                cout<<"\n";
                balancetree(p);
            }
            else if(cur->rightn()==NULL)
            {
                cout<<cur->getkey()<<" hey\n";
                node* p;
                p=cur->parentn();
                if(p!=NULL)
                {
                    if(p->leftn()==cur)
                    {
                        p->newleft(cur->leftn());
                        (cur->leftn())->newparent(p);
                    }
                    else if(p->rightn()==cur)
                    {
                        p->newright(cur->leftn());
                        (cur->leftn())->newparent(p);
                    }
                }
                else
                {
                    root=cur->leftn();
                    root->newparent(NULL);
                }
                delete cur;
                cur=NULL;
                cout<<"\nTree after deletion: \n";
                display();
                cout<<"\n";
                balancetree(p);
            }
            else if(cur->leftn()!=NULL && cur->rightn()!=NULL)
            {
                node* suc;
                suc=successor(cur);
                cur->setkey(suc->getkey());
                cur->setvalue(suc->getvalue());
                node* p;
                p=suc->parentn();
                if(suc->rightn()!=NULL)
                {
                    if(p->rightn()==suc)
                    {
                        p->newright(suc->rightn());
                        (suc->rightn())->newparent(p);
                    }
                    else if(p->leftn()==suc)
                    {
                        p->newleft(suc->rightn());
                        (suc->rightn())->newparent(p);
                    }
                }
                else
                {
                    if(p->rightn()==suc)
                    {
                        p->newright(NULL);
                    }
                    else if(p->leftn()==suc)
                    {
                        p->newleft(NULL);
                    }
                }
                delete suc;
                suc=NULL;
                cout<<"\nTree after deletion: \n";
                display();
                cout<<"\n";
                balancetree(p);
            }
        }
        else if(cur==NULL)
        {
            cout<<"\nNo node with key "<<k<<"(of the given iterator) found!\n";
            // no match found to delete
        }
    }
}

node* AVLtree::successor(node* n)
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
            return NULL;
            // no successor
        }
    }
}

node* AVLtree::predecessor(node* n)
{
    node* cur;
    node* prev;
    cur=n;
    if(cur->leftn()!=NULL)
    {
        cur=cur->leftn();
        while(cur->rightn()!=NULL)
        {
            cur=cur->rightn();
        }
        return cur;
    }
    else
    {
        prev=cur;
        cur=cur->parentn();
        while(cur!=NULL && cur->rightn()!=prev)
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
            return NULL;
            // no predecessor
        }
    }
}

void AVLtree::balancetree(node* n)
{
    node* cur;
    cur=n;
    while(cur!=NULL && isbalanced(cur))
    {
        cur->setheight(finalheight(cur));
        cur=cur->parentn();
    }
    if(cur!=NULL)
    {
        node* x;
        node* y;
        node* z;
        z=cur;
        y=selectmaxin(z);
        x=selectmaxin(y);
        if(z->leftn()==y && y->leftn()==x)
        {
            if( y->rightn()!=NULL && y->leftn()!=NULL && ((y->rightn())->getheight()==(y->leftn())->getheight()))
            {
                rightrotate(z);
                z->setheight(z->getheight()-1);
                y->setheight(y->getheight()+1);
            }
            else
            {
                rightrotate(z);
                z->setheight(z->getheight()-2);
                balancetree(y->parentn());
            }
        }
        else if(z->rightn()==y && y->rightn()==x)
        {
            if( y->rightn()!=NULL && y->leftn()!=NULL && ((y->rightn())->getheight()==(y->leftn())->getheight()))
            {
                leftrotate(z);
                z->setheight(z->getheight()-1);
                y->setheight(y->getheight()+1);
            }
            else
            {
                leftrotate(z);
                z->setheight(z->getheight()-2);
                balancetree(y->parentn());
            }
        }
        else if(z->rightn()==y && y->leftn()==x)
        {
            rightrotate(y);
            leftrotate(z);
            x->setheight(x->getheight()+1);
            y->setheight(y->getheight()-1);
            z->setheight(z->getheight()-2);
            balancetree(x->parentn());
        }
        else if(z->leftn()==y && y->rightn()==x)
        {
            leftrotate(y);
            rightrotate(z);
            x->setheight(x->getheight()+1);
            y->setheight(y->getheight()-1);
            z->setheight(z->getheight()-2);
            balancetree(x->parentn());
        }
    }
    else
    {
        // the tree is balanced
    }
}

node* AVLtree::selectmaxin(node* n)
{
    node* l;
    node* r;
    int hl,hr;
    l=n->leftn();
    r=n->rightn();
    if(l==NULL && r!=NULL)
    {
        return r;
    }
    else if(l!=NULL && r==NULL)
    {
        return l;
    }
    hl=l->getheight();
    hr=r->getheight();
    if(hl>hr)
    {
        return l;
    }
    else if(hl<hr)
    {
        return r;
    }
    else
    {
        node* p;
        p=n->parentn();
        if(p->leftn()==n)
        {
            return l;
        }
        if(p->rightn()==n)
        {
            return r;
        }
    }
}

AVLtree::~AVLtree()
{
    //dtor
}
