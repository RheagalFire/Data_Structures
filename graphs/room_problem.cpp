class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool *visited=new bool[rooms.size()];
	for(int i=0;i<rooms.size();i++)
	{
		visited[i]=false;
	}

	queue<int>q;
	visited[0]=true;
	q.push(0);
	while(!q.empty())
	{
		int node=q.front();
        q.pop();
		for(int i:rooms[node])
		{
			if(!visited[i])
			{
				visited[i]=true;
				q.push(i);
			}
		}
        
	}
    
     for (int i = 0; i < rooms.size(); i++)
     {
        if(!visited[i])
        {
            return false;
        }
    }
        return true;
    }
};
