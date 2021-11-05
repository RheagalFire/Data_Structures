#include<bits/stdc++.h>

using namespace std;


class Graph
{
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addedge(int v,int w);
	void BFS(int s,vector<bool>&visited,queue<int>&q);
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
void Graph::BFS(int s,vector<bool>&visited,queue<int>&q)
{
	if(q.empty())
	{
		return; 
	}
	
	visited[s]=true;
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
	BFS(q.front(),visited,q);
	
}
int main()
{
	vector<bool> visited(4,false);
	queue<int>q;
	Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 3);
    g.addedge(3, 2);
    q.push(0);
    g.BFS(0,visited,q);
}
