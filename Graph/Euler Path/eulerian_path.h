vector<int> get_path(vector<vector<int>>& g, stack<int>& st,vector<int>& e)
{  	
	assert(g.size()==e.size())
	vi cnt(2);
	int starting_node =0;
	for(int i=0;i<g.size();i++)
	{
		if(e[i]%2)starting_node=i;
		cnt[e[i]%2]++; 	
	}
	if(cnt[1]!=0&&cnt[1]!=2)return vector<int>({});
	int st=starting_node;
	vector<int> path;   
	while(sta.size() || (e[st]>0))
	{
		//dbg(path); 
		if(!e[st])
		{
			path.pb(st);
			st=sta.top(); 
			sta.pop(); 
		}
		else 
		{
			fr(i,0,k)
			{
				if(g[st][i]==1)
				{
					sta.push(st); 
					g[st][i]=g[i][st]=0; 
					e[st]--; 
					e[i]--; 
					st=i; 
					break; 
				}
			}
		}
		
	}
	//dbg(path); 
	path.push_back(starting_node);
	return path; 
}