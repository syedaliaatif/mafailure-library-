/*
	If you want to get Euler Path 
	call getEulerPath function to 
	get the path.
	
	Time Complexity  - MlogN 
	
	To know more about the algorithm,
	you can read at - http://www.graph-magics.com/articles/euler.php

*/
class EulerPathDirectedGraph
{
	public: 
	int n; 
	vector<set<int>> g; 
	EulerPathDirectedGraph(int N):n(N),g(N){}
	void add_edge(int u,int v)
	{
		g[u].insert(v); 
	}
	int check()
	{
		vi in(n) , out(n); 
		fr(i,0,n)out[i]=g[i].size(); 
		fr(i,0,n)for(auto v:g[i])in[v]++; 
		int cnta=0,cntb=0; 
		int ida=-1,idb=-1; 
		fr(i,0,n)
		{
			if(in[i]==out[i])continue; 
			cnta+=in[i]<out[i]; 
			cntb+=in[i]>out[i]; 
			if(in[i]<out[i])ida=i; 
			else idb=i; 
		}
		if(cnta!=1||cntb!=1)return -1; 
		return ida; 
	}
	vector<int> getEulerPath()
	{
		int st=check(); 
		if(!(~st))return vi({});
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
				u=v; 
			}
		}
		reverse(all(path));
		return path;   	
	}
	
	
};