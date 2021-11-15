#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	map<int,list<int>>adj;
	map<int,bool>visited;
	bool check_cycle_util(int v,bool visited[],int parent);
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int s);
	bool check_cycle();
};

Graph::Graph(int V)
{
	this->V=V;
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int s)
{
	visited[s]=true;
	cout << s << " ";
	for (auto i: adj[s])
	{
		if(!visited[i])
			{DFS(i);}
	}
}

bool Graph::check_cycle()
{
	bool visited[V]={false};
	for(int u=0;u<V;u++)
	{
		if(!visited[u])
		{
			if(check_cycle_util(u,visited,-1))
				return true;
		}
	}

	return false;
}

bool Graph::check_cycle_util(int v,bool visited[],int parent)
{
	visited[v]=true;
	for(auto i: adj[v])
	{
		if(!visited[i])
		{
			if(check_cycle_util(i,visited,v))
				return true;
		}

		else if(i!=parent)
		{
			return true;
		}
	}
	return false;
}




int main(){
	// Graph g(4);
 //    g.addEdge(0, 1);
 //    g.addEdge(0, 2);
 //    g.addEdge(1, 2);
 //    g.addEdge(2, 0);
 //    g.addEdge(2, 3);
 //    g.addEdge(3, 3);
  
 //    cout << "Following is Depth First Traversal"
 //            " (starting from vertex 2) \n";
    // g.DFS(2);
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.check_cycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";

    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.check_cycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 

} 
