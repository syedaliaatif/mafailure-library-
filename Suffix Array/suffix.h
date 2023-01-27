#include<bits/stdc++.h>
using namespace std; 

class SuffixArray
{
	vector<int> doCyclicShiftSort(string & s)
	{
	  int n=s.size(); 
	  const int alphabet=256; 
	  vector<int>p(n),c(n),cnt(max(alphabet,n),0);
	  
	  for(int i=0;i<n;++i)cnt[s[i]]++;
	  for(int i=1;i<alphabet;++i)cnt[i]+=cnt[i-1];
	  for(int i=n-1;i>=0;--i)p[--cnt[s[i]]]=i;
	  
	  int classes=1; 
	  c[p[0]]=0;

	  for(int i=1;i<n;++i)
	  {
		if(s[p[i]]!=s[p[i-1]])++classes;
		c[p[i]]=classes-1;                             
	  }
	  
	  vi pn(n),cn(n);
	  for(int j=0;(1<<j)<n;++j)
	  {
		 
		for(int i=0;i<n;++i)
		{
		  pn[i]=p[i]-(1<<j); 
		  if(pn[i]<0)pn[i]+=n; 
		} 
		fill(cnt.begin(),cnt.begin()+classes,0); 
		for(int i=0;i<n;++i)cnt[c[pn[i]]]++; 
		for(int i=1;i<classes;++i)cnt[i]+=cnt[i-1]; 
		for(int i=n-1;i>=0;--i)p[--cnt[c[pn[i]]]]=pn[i]; 
		cn[p[0]]=0; 
		classes=1; 
		for(int i=1;i<n;++i)
		{
		  pair<int,int> cur={c[p[i]],c[(p[i]+(1<<(j)))%n]}; 
		  pair<int,int> prev={c[p[i-1]],c[(p[i-1]+(1<<(j)))%n]}; 
		  if(cur!=prev)++classes; 
		  cn[p[i]]=classes-1; 
		} 
		c.swap(cn); 
	 
	  }
	  
	  return p;
	   
	}

	public: 
	
	vector<int> getSuffixArray( string S,char add='$')
	{
			s+=string(1,add);
			vector<int> p=doCyclicShiftSort(S);
			p.erase(p.begin());
			return p; 	
	}
	vector<int> getLcp(string s)
	{
		vector<int> p=getSuffixArray(s); 
		vector<int> rank(n); 
		for(int i=0;i<p.size();i++)rank[p[i]]=i; 
		int k=0;
		vector<int> lcp(n-1); 
		for(int i=0;i<n;i++)
		{
			if(rank[i]==n-1){k=0; continue;}
			int j=p[rank[i]+1]; 
			while(i+k<s.size()&&j+k<s.size()&&s[i+k]==s[j+k])k++; 
			lcp[rank[i]]=k; 
			if(k)k--; 
		}
		return lcp;
	}
	

};

/*void STORE_C(vector<int> & c,bool TO_DO)
{
	if(TO_DO==false)return; 
	C.push_back(c); 
} 
vector<int> cyclic_shift_sort(string & s,bool TO_STORE_C=false)
{
  int n=s.size(); 
  const int alphabet=256; 
  vector<int>p(n),c(n),cnt(max(alphabet,n),0);
  for(int i=0;i<n;++i)cnt[s[i]]++;
  for(int i=1;i<alphabet;++i)cnt[i]+=cnt[i-1];
  for(int i=n-1;i>=0;--i)p[--cnt[s[i]]]=i;
  int classes=1; 
  c[p[0]]=0;
  //STORE_C(c,TO_STORE_C); 
  for(int i=1;i<n;++i)
  {
  	if(s[p[i]]!=s[p[i-1]])++classes;
  	c[p[i]]=classes-1;                             
  }
  vi pn(n),cn(n);
  for(int j=0;(1<<j)<n;++j)
  {
     
    for(int i=0;i<n;++i)
    {
      pn[i]=p[i]-(1<<j); 
      if(pn[i]<0)pn[i]+=n; 
    } 
    fill(cnt.begin(),cnt.begin()+classes,0); 
    for(int i=0;i<n;++i)cnt[c[pn[i]]]++; 
    for(int i=1;i<classes;++i)cnt[i]+=cnt[i-1]; 
    for(int i=n-1;i>=0;--i)p[--cnt[c[pn[i]]]]=pn[i]; 
    cn[p[0]]=0; 
    classes=1; 
    for(int i=1;i<n;++i)
    {
      pair<int,int> cur={c[p[i]],c[(p[i]+(1<<(j)))%n]}; 
      pair<int,int> prev={c[p[i-1]],c[(p[i-1]+(1<<(j)))%n]}; 
      if(cur!=prev)++classes; 
      cn[p[i]]=classes-1; 
    } 
    c.swap(cn); 
    //STORE_C(c,TO_STORE_C); 
  }
  return p; 
}

vector<int> cs(string  s)
{
    s += "$";
    vector<int> p = cyclic_shift_sort(s);
    p.erase(p.begin());
    return p; 
} */
