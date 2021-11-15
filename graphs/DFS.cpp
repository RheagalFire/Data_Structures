#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int>*adj;
	map<int,bool>visited;
public:
	Graph(int V);
	void addEdge(int v,int w);
	void DFS(int s);
};

Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
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




int main(){
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);

} 
