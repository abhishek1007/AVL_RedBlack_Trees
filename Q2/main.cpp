#include <iostream>
#include <stdlib.h>
#include "AVLtree.h"
#include <fstream>

using namespace std;

int main()
{
    AVLtree T;
    int c;
    ifstream f1;
    f1.open("input.txt",ios::in);
    while(f1>>c)
    {
        T.put(c,c);
    }
    cout<<"\nThe tree after entering all the elements from the file is: \n";
    T.display();
    cout<<"\n\n\n";
    int input;
    cout<<"Enter the target sum: ";
    cin>>input;
    if(T.targetSum(input))
    {
	cout<<"\nThe given target sum can be achieved\n";	
    }
    else
    {
	cout<<"\nThe given target sum cannot be achieved\n";
    }
    return 0;
}
