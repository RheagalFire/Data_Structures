#include<bits/stdc++.h>

using namespace std;


class Graph
{
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addedge(int v,int w);
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V=V;
	adj = new list<int>[V];
} 
void Graph::addedge(int v,int w)
{
	adj[v].push_back(w);
}
void Graph::BFS(int s)
{
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	queue<int>q;
	visited[s]=true;
	q.push(s);
	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();
		for(int i:adj[s])
		{
			if(!visited[i])
			{
				visited[i]=true;
				q.push(i);
			}
		}
	}
}
int main()
{
	Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(3, 2);

    g.BFS(0);
}
