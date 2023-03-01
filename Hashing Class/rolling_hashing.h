/*
 Use Code submitted in ARC 60 F
*/


template<const int X=2> 
class StringHashing
{
	using T=array<int,X> ; 
	public: 
	function<T(int,int)> get_sub; 
	function<bool(int,int,int,int)> match_two_sub; 
	vector<T> hash,pp,ipp; 
	T p,ip,mod; 
	StringHashing(string  w,int N)
	{
		/*TODO Base values of mod, p, ip needs to be updated if you are using different X*/
		mod={(int)1e9+7,(int)1e8+7}; 
		p={37,43}; 
		ip={power(p[0],mod[0]-2,mod[0]),power(p[1],mod[1]-2,mod[1])}; 
		T base_val; 
		base_val.fill(1); 
	    pp=vector<T>(N,base_val); 
	    ipp=vector<T>(N,base_val); 
		for(int i=1;i<N;i++)
		{
			for(int j=0;j<X;j++)
			{
				pp[i][j]=mul(pp[i-1][j],p[j],mod[j]); 
				ipp[i][j]=mul(ipp[i-1][j],ip[j],mod[j]); 
			}
		}

		int n=w.size(); 
		hash(n+1,base_val); 
		for(int i=0;i<n;i++)
		{
			fr(j,0,X)hash[i+1][j]=add(hash[i][j],mul(pp[i+1][j],w[i]-'a'+1,mod[j]),mod[j]); 
		}
		 get_sub=[&](int l,int r)->T 
		{
			T h; 
			h.fill(0); 
			fr(j,0,X)h[j]=sub(hash[r+1][j],hash[l][j],mod[j]),h[j]=mul(h[j],ipp[l][j],mod[j]);
			return h; 	
		};
		match_two_sub=[&](int la,int ra,int lb,int rb)->bool 
		{
			//if(ra-la!=rb-lb)return false;
			T ha=get_sub(la,ra);
			T hb=get_sub(lb,rb);  
			return ha==hb; 
		};

	
	}
	
	
};