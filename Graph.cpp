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
    cout<<"Enter 5 for Topological Sort"<<endl;
    cout<<"Enter 6 for Finding Sortest path in a unweighted graph"<<endl;
    cout<<"Enter 7 for Find shortest path in weighted graph(DIJKSTRA,S)"<<endl;
    cout<<"Enter 8 for Shortet path using BellmanFord Algo"<<endl;

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
        case 5:
            TopologicalSort(G);
            break;
        case 6:
            ShortestPath(G,0);
            break;
        case 7:
            ShortestPathDijkstra(G,0);
            break;
        case 8:
            ShortestPathBellmanFort(G,0);
            break;
        default:
            cout<<"Not a valid choice";
        }
    }
}



