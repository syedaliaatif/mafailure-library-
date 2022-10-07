#include<bits/stdc++.h>
using namespace std; 
template<class T=int> 
struct FenwickTree:vector<T>
{
	public: 
	inline int lsone(int i){return (i&(-i));}
	template<typename... Args> 
	FenwickTree(Args... args):vector<T>(args...){;}
	void update(int ind,T val,function<T(const T, const T)> f)
	{
		vector<T> & ft= *this; 
		for(int i=ind;i<ft.size();i+=lsone(i))ft[i]=f(ft[i],val); 
	}
	T query(int ind, T ans, function<T(const T,const T)> f)
	{
		vector<T> & ft = *this; 
		for(int i=ind;i;i-=lsone(i))ans=f(ft[i],ans); 
		return ans; 
	}
	T query_max(int ind ,int ans)
	{
	 	return query(ind,ans,[](T a,T b)->T{return a>b?a:b;}); 
	}
	T query_min(int ind,int ans)
	{
		return query(ind, ans,[](T a,T b)->T{return a<b?a:b;}); 
	}
	T query_cnt(int ind,int ans)
	{
		return query(ind, ans, [](T a, T b)->T{return a+b;}); 
	}
	void update_max(int ind,int val)
	{
		update(ind,val,[](T a,T b){return a>b?a:b;}); 
	}
	void update_min(int ind,int val)
	{
		update(ind,val,[](T a,T b){return a<b?a:b;}); 
	}
	void update_cnt(int ind,int val)
	{
		update(ind,val,[](T a,T b){return a+b;}); 
	}
	
	
	
};
