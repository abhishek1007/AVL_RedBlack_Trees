#include <iostream>
#include <stdlib.h>
#include "RedBlacktree.h"
#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    RedBlacktree T;
    T.display();
    int i;

    for(i=1;i<=30;i++)
    {
        T.insert(i,i);
    }
    vector<int> c;

    T.display();
    //T.remove(13);
    T.search(100);
    c=T.inorder(8,220);

    for(i=0;i<c.size();i++)
    {
        cout<<c[i]<<"  ";
    }

    cout<<"\nno of leaves: \n";
    cout<<T.tree_blackheight();
    return 0;
}
