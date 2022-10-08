/* 
	Test File For Suffix Array
	Submission Link - https://atcoder.jp/contests/abc272/submissions/35518131
 */ 

/* Creation Date - 08-10-2022 */  
/* Creation Time - 17:28:08.43 */  

#define ill 
#define AATIF_DEBUG
/*
Written By : mafailure
In the name of God 
O Allah, May you grant peace and honor on Muhammad and his family.
Allahumm-a-Sall-iAla Muhammad-in Wa Al-i Muhammad
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
#define endl "\n"
/*------------------------int to long long -----------------*/
#ifdef ill
#define int long long 
#endif
/*---------------------------DEBUG HELPER--------------------------------------*/

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T,typename K> ostream& operator<<(ostream & os,const map<T,K> & mapp){ os<<"{"; string sep=""; for(const auto& x:mapp)os<<sep<<x,sep=", "; return os<<'}'; }
template <typename T> ostream & operator<<(ostream & os,const set<T> & sett){os<<'{'; string sep=""; for(const auto & x:sett)os<<sep<<x,sep=", "; return os<<'}';}
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef AATIF_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
//#define int long long 
// int dx[]={-1,1,0,0}; int dy[]={0,0,1,-1};
// int dx[]={2,2,-2,-2,1,1,-1,-1}; int dy[]={1,-1,1,-1,2,-2,2,-2};
#ifndef mod_2 
long long mod = 1e9 + 7;
#else 
long long mod =998244353; 
#endif 
const double eps=1e-9;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector< pair< int, int > > vii;
typedef map<int, int> mii;
typedef pair<int, ii> pip;
typedef pair<ii, int> ppi;
#define arrinp(arr,init,final,size,type) type* arr=new type[size];for(int i=init;i<final;i++)cin>>arr[i];
#define cr2d(arr,n,m,t) t**arr=new t*[n];for(int i=0;i<n;i++)arr[i]=new t[m];
#define w(t) int t;cin>>t; while(t--)
#define takeInp(n) int n;cin>>n;
#define fr(i,init,final) for(int i=init;i<final;i++)
#define frr(i,init,final) for(int i=init;i>=final;i--)
#define Fr(i,final) for(int i=0;i<final;i++)
#define Frr(i,first) for(int i=first;i>=0;i--)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
//#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;
#define setb __builtin_popcount
#define lsone(n) (n&(-n))
#define rlsone(n) (n&(n-1))
#define clr(a,b) memset(a,b,sizeof(a))
#ifdef ill 
const int inf =1e18; 
#else 
const int inf=1e9;
#endif
/*-----------------------------RANDOM NUMBER GENERATOR ---------------------*/
#ifdef RNG 
unsigned seed=chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);
#endif 
/*------------------------------UNORDERED MAP HASH --------------------------------------------*/
//To make unordered_map unhackable 
// use it as unordered_map<int,int,custom_hash> mapp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*---------------------------ORDERED SET--------------------------------------*/
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  ordered_set; 
/*----------------------------------------------------------------------------*/
vi init(string s)
{
	istringstream sin(s);
	int n;
	vi arr;
	while(sin>>n)arr.push_back(n);
	return arr;
}
int power(int x, int y)
{ 
	if(y==0)return 1;
	int u=power(x,y/2);
	u=(u*u)%mod;
	if(y%2)u=(x*u)%mod;
	return u;
    
}
int gcd(int a,int b)
{
	if(a<b)return gcd(b,a);
	return (b==0?a:(a%b?gcd(b,a%b):b));
}
int gcd_e(int a,int b,int &x,int &y)
{
	
	if(b==0){x=1; y=0; return a;}
	int x1,y1;
	int p=gcd_e(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return p;
}
/*-----------------to solve int to long long problem-----------------*/
int Min (int a,int b){return min(a,b);}
int Max(int a,int b){ return max(a,b);}
inline int add(int a,int b,int mod=mod){return (a+b)%mod;} 
inline int sub(int a,int b,int mod=mod){return (a-b+mod)%mod;}
inline int mul(int a,int b,int mod=mod){return (a*b%mod);}
inline int divide(int a,int b,int mod=mod){return a*power(b,mod-2)%mod;}
inline int high(int a,int b){return (a>>b)&1;}

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
}









/*---------------------KASAI's ALGORITHM----------------*/
/*
  LCP[i] is the maximum length of common prefix of suffix[p[i]] and suffix[p[i+1]]
  So if you need the the Longest Common prefix between any arbitrary suffix starting at i 
  and other starting at j 
  let's say there position in sorted form is rank[i] and rank[j]
  then longest common prefix will be min(LCP[rank[i]],......LCP[rank[j]])

*/




vector<int> lcp_generate(string & s,vector<int> & p)
{
	int n=s.size(); 
	vector<int> rank(n); 
	for(int i=0;i<n;i++)rank[p[i]]=i; 
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




signed main()
{
	IOS
	int n; 
	cin>>n; 
	string s; 
	cin>>s; 
	string t; 
	cin>>t; 
	string com=s+s+t+t;
	vector<int> suf=cs(com); 
	vector<int> lcp=lcp_generate(com,suf); 
	//vector<int> & suf=SAAA.SA; 	
	//dbg(suf);  
	int cnt=0; 
	int ans=0; 
	//dbg(0,n,2*n,3*n); 
	for(int i=suf.size()-1;i>=0;)
	{
		int j=i; 
		cnt+=suf[i]>=2*n&&suf[i]<3*n; 
		while(j>0&&lcp[j-1]>=n)
		{
			j--; 
			if(suf[j]>=2*n&&suf[j]<3*n)cnt++; 
		}
		//dbg(j,i,cnt); 
		while(i>=j)
		{
			if(suf[i]<n)ans+=cnt; 
			i--; 
		}
	}
	cout<<ans<<endl; 
	 
	
	
	
	
		 
}



