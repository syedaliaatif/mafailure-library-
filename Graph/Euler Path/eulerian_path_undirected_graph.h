/*

Hierholzer's Algorithm -  http://stones333.blogspot.com/2013/11/find-eulerian-path-in-directed-graph.html
Time Complexity - MLogN time 
getEulerPath returns the path where path[i] = is a pair of edge 

*/
class EulerianPathUndirectedGraph
{
	
	public: 
	vector<set<int>> g;
	int n;
	EulerianPathUndirectedGraph(int N):g(N),n(N){}
	void add_edge(int u,int v)
	{
		g[u].insert(v);
		g[v].insert(u);   
	}
	int check()
	{
		int cnt=0;
		int id=-1; 
		for(int i=0;i<n;i++)
		{
			cnt+=((int)g[i].size()%2);
			if((int)g[i].size()%2)id=i;
		}
		 
		if(cnt>2)return -1; 
		if(cnt==0)return 0; 
		return id; 
		
	}
	ii getUnvisitedEdge(int u)
	{
		if(g[u].empty())return mp(-1,-1); 
		int v=*g[u].begin();
		return mp(u,v);
	}
	vector<int> getEulerPath()
	{
		int st=check(); 
		if(st==-1)return vi({}); 
		stack<int> forward; 
		vector<int> path; 
		int u=st; 
		while(1)
		{
			if(g[u].empty())
			{
				path.push_back(u); 
				if(forward.empty())break; 
				u=forward.top(); 
				forward.pop(); 
			}
			else 
			{
				forward.push(u); 
				int v=*g[u].begin(); 
				g[u].erase(v); 
				g[v].erase(u); 
				u=v; 
			}
		}
		reverse(all(path)); 
		return path; 	
	}
	
	
};