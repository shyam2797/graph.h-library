#include<queue>
struct Graph
{
    int V,E;
    int **adj;
};
void print(struct Graph * G)
{
    for(int u=0; u<G->V; u++)
    {
        for(int v=0; v<G->V; v++)
        {
            std::cout<<G->adj[u][v]<<" ";
        }
        std::cout<<std::endl;
    }
}
struct Graph * adjGraph()
{
    int i,u,v;
    Graph * G = new Graph();
    std::cout<<"Enter the number of vertices and edges in the graph :"<<std::endl;
    std::cin>>G->V>>G->E;
    G->adj = new int*[G->V];
    for(int i = 0; i < G->V; ++i)
    {
        G->adj[i] = new int[G->V];
    }
    for(int u=0; u<G->V; u++)
    {
        for(int v=0; v<G->V; v++)
        {
            G->adj[u][v]=0;
        }
    }
    std::cout<<"Enter All the edges of the Graph:"<<std::endl;
    for(int i=0; i<G->E; i++)
    {
        std::cin>>u>>v;
        G->adj[u][v]=1;
        G->adj[v][u]=1;
    }
    return G;

}
void DFS(struct Graph * G,int start,int arr[])
{
    std::cout<<start<<" ";
    arr[start]=1;
    for(int v=0; v<G->V; v++)
    {
        if(!arr[v] && G->adj[start][v])
        {
            DFS(G,v,arr);
        }
    }
}
void DFSTraversal(struct Graph * G)
{
    int visited[G->V];
    for(int i=0; i<G->V; i++)
        visited[i]=0;
    for(int i=0; i<G->V; i++)
    {
        if(!visited[i])
            DFS(G,i,visited);
    }
    std::cout<<std::endl;
}
void BFS(Graph * G,int start,int arr[])
{
    int u;
    std::queue<int>Q;
    Q.push(start);
    while(!Q.empty())
    {
        u=Q.front();
        std::cout<<u<<" ";
        arr[u]=1;
        Q.pop();
        for(int v=0; v<G->V; v++)
        {
            if(!arr[v] && G->adj[u][v])
            {
                Q.push(v);
            }
        }

    }

}

void BFSTraversal(struct Graph * G)
{
    int visited[G->V];
    for(int i=0; i<G->V; i++)
        visited[i]=0;
    for(int i=0; i<G->V; i++)
    {
        if(!visited[i])
            BFS(G,i,visited);
    }
    std::cout<<std::endl;

}

