#include <iostream>
#include <stdlib.h>
#include "AVLtree.h"

using namespace std;

int main()
{
    int op;
    AVLtree T;
/*
    int i;
    for(i=1;i<=30;i++)
    {
        T.put(i,i);
    }
*/
    while(op!=0){
    cout<<"\n-----OPTIONS-----\n\n1) firstEntry()\n2) lastEntry()\n3) ceilingEntry(k)\n4) floorEntry(k)\n5) lowerEntry(n)\n6) higherEntry(k)\n7) size()\n8) empty()\n9) find(k)\n10) put(k,v)\n11) erase(k)\n12) erase(p)\n\nEnter 0 to Exit the program\n\nEnter your option: ";
    cin>>op;
    if(op==1)
    {
	if(T.firstEntry()!=T.end())
	{
	    cout<<"First Entry is: ("<<((*(T.firstEntry())).getk())<<","<<((*(T.firstEntry())).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==2)
    {
	if(T.lastEntry()!=T.end())
	{
	    cout<<"Last Entry is: ("<<((*(T.lastEntry())).getk())<<","<<((*(T.lastEntry())).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}

    }
    else if(op==3)
    {
	int k;
	cout<<"Enter the key: ";
	cin>>k;
	if(T.ceilingEntry(k)!=T.end())
	{
	    cout<<"Ceiling Entry is: ("<<((*(T.ceilingEntry(k))).getk())<<","<<((*(T.ceilingEntry(k))).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==4)
    {
	int k;
	cout<<"Enter the key: ";
	cin>>k;
	if(T.floorEntry(k)!=T.end())
	{
	    cout<<"Floor Entry is: ("<<((*(T.floorEntry(k))).getk())<<","<<((*(T.floorEntry(k))).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==5)
    {
	int k;
	cout<<"Enter the key: ";
	cin>>k;
	if(T.lowerEntry(k)!=T.end())
	{
	    cout<<"Lower Entry is: ("<<((*(T.lowerEntry(k))).getk())<<","<<((*(T.lowerEntry(k))).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==6)
    {
	int k;
	cout<<"Enter the key: ";
	cin>>k;
	if(T.higherEntry(k)!=T.end())
	{
	    cout<<"Higher Entry is: ("<<((*(T.higherEntry(k))).getk())<<","<<((*(T.higherEntry(k))).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==7)
    {
	cout<<"\nThe size of the tree is: "<<T.size()<<"\n";
    }
    else if(op==8)
    {
	if(T.empty())
	{
	    cout<<"\nThe tree is empty\n";
	}
	else
	{
	    cout<<"\nThe tree is not empty\n";
	}
    }
    else if(op==9)
    {
	int k;
	cout<<"Enter the key to find: ";
	cin>>k;
	if(T.find(k)!=T.end())
	{
	    cout<<"Entry found : ("<<((*(T.find(k))).getk())<<","<<((*(T.find(k))).getval())<<")\n";
	}
	else
	{
	    cout<<"End iterator was returned\n";
	}
    }
    else if(op==10)
    {
	int k;
	cout<<"Enter the key to insert: ";
	cin>>k;
	int v;
	cout<<"Enter the value to insert: ";
	cin>>v;
	cout<<"Inserted Enrty:("<<((*(T.put(k,v))).getk())<<","<<((*(T.put(k,v))).getval())<<")\n";
    }
    else if(op==11)
    {
	int k;
	cout<<"Enter the key to remove: ";
	cin>>k;
	T.erase(k);
    }
    else if(op==12)
    {

    }
    else if(op!=0)
    {
	cout<<"INVALID OPTION ENTERED!\nENTER AGAIN...\n";
    }
    }

    return 0;
}
