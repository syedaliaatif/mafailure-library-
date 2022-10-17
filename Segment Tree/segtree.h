

template<class T=int, class L=int, class A=int> 
class segTree
{
	public: 
	#define left (p<<1)
	#define right (left|1)
	#define mid ((l+r)>>1)
	#define toleft left,l,mid
	#define toright right,mid+1,r 
	int n; 
	vector<T> t; 
	vector<L> lazy; 
	vector<A> a; 
	//T tmp; 
	segTree(int n):n(n),t(4*n),lazy(4*n){}
	T mer(T a, T b)
	{
		return T(); 
	}
	void build(int p,int l,int r)
	{
		if(l==r)
		{
			t[p]=a[l]; 
			return void(); 
		}
		build(toleft); 
		build(toright); 
		t[p]=mer(t[left],t[right]); 
	}
	void push(int p,int l,int r)
	{
		return; 
	}
	T query(int p,int l,int r,int i,int j)
	{
		push(p,l,r);
		if(i<=l&&r<=j)return t[p]; 
		if(j<=mid)return query(toleft,i,j); 
		if(i>mid)return query(toright,i,j); 
		return mer(query(toleft,i,j),query(toright,i,j)); 
	}
	template<typename V, typename ...Args>
	void lazy_oper(int p,int l,int r,int val,Args...args)
	{
	   
	   return; 
	}
	template<typename... V> 
	void update(int p,int l,int r,int i,int j,V... val)
	{
		push(p,l,r); 
		if(r<i||l>j)return void(); 
		if(i<=l&&r<=j)
		{
			lazy_oper(p,l,r,val...); 
			push(p,l,r);
			return;  
		}
		update(toleft,i,j,val...);
		update(toright,i,j,val...); 
		t[p]=mer(t[left],t[right]); 
	}
	#undef toright 
	#undef toleft 
	#undef mid
	#undef right
	#undef left 
	
};