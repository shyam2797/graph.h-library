#include<bits/stdc++.h>
#include"graph.h"
using namespace std;
int main()
{
    int v,u,n;
    struct Graph * G;
    G=adjGraph();
    cout<<"Enter a choice:"<<endl;
    cout<<"Enter 1 for print the graph"<<endl;
    while(1)
    {
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            print(G);
            break;
        case 2:
            DFSTraversal(G);
            break;
        case 3:
            BFSTraversal(G);
            break;
        default:
            cout<<"Not a valid choice";
        }
    }
}



