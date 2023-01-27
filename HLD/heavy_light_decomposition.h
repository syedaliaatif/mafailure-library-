
using namespace std;

template <class T = int, class L = int, class A = int>
class segTree
{
public:
#define left (p << 1)
#define right (left | 1)
#define mid ((l + r) >> 1)
#define toleft left, l, mid
#define toright right, mid + 1, r
	int n;
	vector<T> t;
	vector<L> lazy;
	vector<A> a;
	// T tmp;
	segTree(int n) : n(n), t(4 * n), lazy(4 * n) {}
	T mer(T a, T b);
	void build(int p, int l, int r)
	{
		if (l == r)
		{
			t[p] = a[l];
			return void();
		}
		build(toleft);
		build(toright);
		t[p] = mer(t[left], t[right]);
	}
	void push(int p, int l, int r);
	T query(int p, int l, int r, int i, int j)
	{
		push(p, l, r);
		if (i <= l && r <= j)
			return t[p];
		if (j <= mid)
			return query(toleft, i, j);
		if (i > mid)
			return query(toright, i, j);
		return mer(query(toleft, i, j), query(toright, i, j));
	}
	template <typename V, typename... Args>
	void lazy_oper(int p, int l, int r, V val, Args... args);
	template <typename... V>
	void update(int p, int l, int r, int i, int j, V... val)
	{
		push(p, l, r);
		if (r < i || l > j)
			return void();
		if (i <= l && r <= j)
		{
			lazy_oper(p, l, r, val...);
			push(p, l, r);
			return;
		}
		update(toleft, i, j, val...);
		update(toright, i, j, val...);
		t[p] = mer(t[left], t[right]);
	}
#undef toright
#undef toleft
#undef mid
#undef right
#undef left
};

template <class T = int, class L = int, class A = int>
class HLD
{
public:
	segTree<T, L, A> seg;
#define Seg seg
#undef w
	vvi g;
	vi depth, par, heavy, node, pos, head, w;

	int n, cur_pos;
	HLD(int n) : n(n), g(n), cur_pos(0), depth(n), par(n), w(n), heavy(n, -1), node(n), pos(n), head(n), seg(n) {}
	void dfs(int u, int p)
	{
		w[u] = 1;
		heavy[u] = -1;
		int size = 0;
		par[u] = p;
		// if(g[u].size()==1)leaf[u]=1;
		// else leaf[u]=0;
		for (auto v : g[u])
		{
			if (v == p)
				continue;
			depth[v] = depth[u] + 1;
			dfs(v, u);
			// leaf[u]+=leaf[v];
			w[u] += w[v];
			if (w[v] > size)
				size = w[v], heavy[u] = v;
		}
	}

	void decompose(int u, int h)
	{
		head[u] = h;
		pos[u] = cur_pos++;
		node[pos[u]] = u;
		if (~heavy[u])
			decompose(heavy[u], h);
		for (auto v : g[u])
		{
			if (v == par[u] || v == heavy[u])
				continue;
			decompose(v, v);
		}
	}
	T mer(T a, T b);

	template <typename V>
	void update(int u, int v, V val)
	{
		for (; head[u] != head[v]; v = par[head[v]])
		{
			if (depth[head[u]] > depth[head[v]])
				swap(u, v);
			seg.update(1, 0, n - 1, pos[head[v]], pos[v], val);
		}
		if (depth[u] > depth[v])
			swap(u, v);
		seg.update(1, 0, n - 1, pos[u], pos[v], val);
	}
	T query(int u, int v, T ans)
	{
		for (; head[u] != head[v]; v = par[head[v]])
		{
			if (depth[head[u]] > depth[head[v]])
				swap(u, v);
			// dbg(head[v],v);
			ans = mer(ans, seg.query(1, 0, n - 1, pos[head[v]], pos[v]));
		}
		// dbg(u,v);
		if (depth[u] > depth[v])
			swap(u, v);

		return ans = mer(ans, seg.query(1, 0, n - 1, pos[u], pos[v]));
	}
	void solve();
};
