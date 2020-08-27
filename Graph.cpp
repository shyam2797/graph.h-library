#include<bits/stdc++.h>
#include"graph.h"
using namespace std;
int main()
{
    int v,u,n;
    struct Graph * G;
    G=adjGraph();
    cout<<"Enter a choice:"<<endl;
    cout<<"Enter 1 for print"<<endl;
    cout<<"Enter 2 for Depth First Traversal"<<endl;
    cout<<"Enter 3 for Breadth First Traversal"<<endl;
    cout<<"Enter 4 for All Pair Shortest Path"<<endl;
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
        case 4:
            AllPairShortestPath(G);
            break;
        default:
            cout<<"Not a valid choice";
        }
    }
}



