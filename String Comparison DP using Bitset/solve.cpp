/* Creation Date - 19-10-2022 */  
/* Creation Time -  1:40:50.31 */  

/*
Written By : mafailure
In the name of God 
O Allah, May you grant peace and honor on Muhammad and his family.
Allahumm-a-Sall-iAla Muhammad-in Wa Al-i Muhammad
*/
#ifdef LOCAL 
#define AATIF_DEBUG
#endif 
  
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
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;
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
//786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121 786 121
/*========================CODE*****CODE****CODE======================*/

const int N=2e6+5; 
bitset<N> State,Heap[65];
vector<int> idx; 
bool dp[2001][10001];
char get_smallest()
{
	int cur=1; 
	while(cur<32)
	{
		if((State&Heap[2*cur]).none())cur=cur*2+1; 
		else cur*=2; 
	}
	return cur-32+'a'; 
}

signed main()
{
	IOS
	State.reset();
	for(int i=0;i<65;i++)Heap[i].reset();
	int n;
	int k;
	cin>>n>>k;
	vector<string> a(n);
	for(auto & it:a)cin>>it;
	string s;
	idx=vi(n+1); 
	for(int i=0;i<n;i++)
	{
		idx[i]=s.size(); 
		for(int j=0;j<a[i].size();j++)
		s.push_back(a[i][j]);
	}
	idx.back()=s.size(); 
	for(int i=0;i<s.size();i++)
	{
		Heap[s[i]-'a'+32].set(i); 
	}
	for(int i=31;i>=1;i--)
	{
		Heap[i]=Heap[2*i]|Heap[2*i+1]; 
	}
	State.set(0,true);
	
	dp[n][0]=1; 
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=k;j++)
		{
			if(dp[i+1][j])
			{
				dp[i][j]=1;
				if(j+a[i].size()<=k)dp[i][j+a[i].size()]=1;
			}
		}
	}
	string ans=""; 
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(State[idx[j]])State.set(idx[j+1]); 
		}
		for(int j=0;j<n;j++)
		{
			if(k-i<a[j].size()||!dp[j+1][k-i-a[j].size()])
			State.reset(idx[j]); 
		}
		
		char c=get_smallest(); 
		ans+=c; 
		State&=Heap[c-'a'+32]; 
		State<<=1;
	}
	cout<<ans<<endl; 
	
	
	
	 
	
		 
}



