#include<queue>
using namespace std;
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
    int wh;
    std::cout<<"Is this a weighted graph,if yes then press 1 else 0"<<std::endl;
    std::cin>>wh;
    if(wh==1)
    {
        int dh,w;
        std::cout<<"Enter 1 if graph is directed else 0:"<<std::endl;
        std::cin>>dh;
        if(dh==0)
        {
            std::cout<<"Enter All the edges of the Graph and weight:"<<std::endl;
            for(int i=0; i<G->E; i++)
            {
                std::cin>>u>>v>>w;
                G->adj[u][v]=w;
                G->adj[v][u]=w;
            }
        }
        else
        {
            std::cout<<"Enter All the edges of the Graph and weight:"<<std::endl;
            for(int i=0; i<G->E; i++)
            {
                std::cin>>u>>v>>w;
                G->adj[u][v]=w;
            }
        }
    }
    else
    {
        int dh;
        std::cout<<"Enter 1 if graph is directed else 0:"<<std::endl;
        std::cin>>dh;
        if(dh==0)
        {
            std::cout<<"Enter All the edges of the Graph:"<<std::endl;
            for(int i=0; i<G->E; i++)
            {
                std::cin>>u>>v;
                G->adj[u][v]=1;
                G->adj[v][u]=1;
            }
        }
        else
        {
            std::cout<<"Enter All the edges of the Graph:"<<std::endl;
            for(int i=0; i<G->E; i++)
            {
                std::cin>>u>>v;
                G->adj[u][v]=1;
            }
        }
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
void AllPairShortestPath(Graph * G)
{
    int Max=10000;
    int mat[G->V][G->V];
    for(int i=0; i<G->V; i++)
    {
        for(int j=0; j<G->V; j++)
        {
            if(i==j)
            {
                mat[i][j]=0;
            }
            else if(G->adj[i][j]!=0)
            {
                mat[i][j]=G->adj[i][j];
            }
            else
            {
                mat[i][j]=Max;
            }
        }
    }
    for(int k=0; k<G->V; k++)
    {
        for(int i=0; i<G->V; i++)
        {
            for(int j=0; j<G->V; j++)
            {
                mat[i][j]=mat[i][j]<(mat[i][k]+mat[k][j])?mat[i][j]:(mat[i][k]+mat[k][j]);
            }
        }
    }
    for(int i=0; i<G->V; i++)
    {
        for(int j=0; j<G->V; j++)
        {
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

}
void TopologicalSort(Graph * G)
{
    int indegree[G->V],TO[G->V];
    for(int i=0; i<G->V; i++)
        indegree[i]=0;
    for(int i=0; i<G->V; i++)
    {
        for(int j=0; j<G->V; j++)
        {
            if(G->adj[i][j])
            {
                indegree[j]++;
            }
        }
    }
    int counter=0;
    std::queue<int>Q;
    for(int i=0; i<G->V; i++)
    {
        if(indegree[i]==0)
        {
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        TO[v]=counter++;
        for(int i=0; i<G->V; i++)
        {
            if(i!=v && G->adj[v][i]!=0)
            {
                indegree[i]--;
                if(indegree[i]==0)
                    Q.push(i);
            }
        }

    }
    if(counter!=G->V)
    {
        std::cout<<"There is a cycle in the graph!"<<std::endl;
    }
    else
    {
        for(int i=0; i<G->V; i++)
        {
            std::cout<<i<<"------>"<<TO[i]<<std::endl;
        }
    }
}
void ShortestPath(Graph * G,int source)
{
    int u,v,w;
    queue<int>Q;
    int distance[G->V],path[G->V];
    for(int i=0; i<G->V; i++)
    {
        distance[i]=-1;
        path[i]=-1;
    }
    distance[source]=0;
    Q.push(source);
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        for(w=0; w<G->V; w++)
        {
            if(G->adj[v][w] && distance[w]==-1)
            {
                distance[w]=distance[v]+1;
                path[w]=v;
                Q.push(w);
            }
        }

    }
    for(int i=0; i<G->V; i++)
    {
        cout<<"Path "<<path[i]<<" Distance "<<distance[i]<<endl;
    }
    return;

}
void ShortestPathDijkstra(Graph * G,int source)
{
    typedef pair<int, int> pd;

// Structure of the operator
// overloading for comparison
    struct myComp
    {
        constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
        const noexcept
        {
            return a.second > b.second;
        }
    };
    int u,v,w;
    priority_queue< pd,vector<pd>,myComp >Q;
    int distance[G->V],path[G->V],visited[G->V];
    for(int i=0; i<G->V; i++)
    {
        distance[i]=-1;
        path[i]=-1;
        visited[i]=0;
    }
    distance[source]=0;
    Q.push(make_pair(source,distance[source]));
    while(!Q.empty())
    {
        int v=Q.top().first;
        int d=Q.top().second;
        Q.pop();
        if(visited[v]!=1)
        {
            visited[v]=1;
            distance[v]=d;
            //cout<<"v "<<v<<" p "<<path[v]<<" d "<<distance[v]<<endl;
            for(w=0; w<G->V; w++)
            {
                if(G->adj[v][w] && distance[w]==-1)
                {

                    distance[w]=distance[v]+G->adj[v][w];
                    path[w]=v;
                    Q.push(make_pair(w,distance[w]));
                    // cout<<"v "<<v<<"w "<<w<<"p "<<path[w]<<"d "<<distance[w]<<endl;
                }
                else if(G->adj[v][w] && visited[w]!=1 && (distance[w] > distance[v]+G->adj[v][w]) )
                {
                    distance[w]=distance[v]+G->adj[v][w];
                    path[w]=v;
                    Q.push(make_pair(w,distance[w]));
                    //cout<<"v "<<v<<"w "<<w<<"p "<<path[w]<<"d "<<distance[w]<<endl;
                }
            }
        }

    }
    for(int i=0; i<G->V; i++)
    {
        cout<<"Path "<<path[i]<<" Distance "<<distance[i]<<endl;
    }
    return;
}
void ShortestPathBellmanFort(Graph * G,int source)
{
    int u,v,w;
    queue<int>Q;
    int distance[G->V],path[G->V];
    for(int i=0; i<G->V; i++)
    {
        distance[i]=1000;
        path[i]=-1;
    }
    distance[source]=0;
    Q.push(source);
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        for(w=0; w<G->V; w++)
        {
            if(G->adj[v][w] && distance[w] > distance[v]+G->adj[v][w])
            {
                distance[w]=distance[v]+G->adj[v][w];
                path[w]=v;
                Q.push(w);
            }
        }

    }
    for(int i=0; i<G->V; i++)
    {
        cout<<"Path "<<path[i]<<" Distance "<<distance[i]<<endl;
    }
    return;
}
