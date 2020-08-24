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



