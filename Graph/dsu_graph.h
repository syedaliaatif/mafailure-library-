// Class to be used in problems where you need some property for
// the whole subtree of each node.
// Time Complexity: NLogN*(phi)
// Where phi is the complexity to store the property of each node
// If you are using map than it becomes Nlog^2N
// If you are using simple array than it is NLogN

class DsuGraph
{
public:
	struct E
	{
		int to, w, idx;
	};
	vector<vector<E>> g;
	int n;
	DsuGraph(int N) : n(N), g(n) {}
	function<void(int, int)> firstDfs;
	function<void(int, int, int)> secondDfs;
	function<void(int )> insert,restore; 

	void add_edge(int u, int v, int w = 1, int idx = -1)
	{
		assert(u >= 0 && u < n && v >= 0 && v < n);
		g[u].push_back(E({v, w, idx}));
		g[v].push_back(E({v, w, idx}));
	}
	void solve(int root = 0)
	{
		vi w(n, 1), par(n, -1), heavy(n, -1);
		vector<vi *> vec(n);
		firstDfs = [&](int u, int p)
		{
			w[u] = 1;
			par[u] = p;
			for (auto v : g[u])
			{
				if (v.to == p)
					continue;
				firstDfs(v.to, u);
				w[u] += w[v.to];
				if (w[v.to] > size)
					size = w[v.to], heavy[u] = v.to;
			}
		};

		// Function to insert a node in the ds you are using to store
		// properties of nodes
		 insert = [&](int u)
		{
			return void();
		};
		// Function to delete a node in the ds you are using
		// to store properties of a node
	     restore = [&](int u) {

		};

		secondDfs = [&](int u, int p, int keep)
		{
			for (auto v : g[u])
			{
				if (v.to == p || v.to == heavy[u])
					continue;
				secondDfs(v.to, u, 0);
			}
			if (~heavy[u])
			{
				secondDfs(heavy[u], u, 1);
				vec[u] = vec[heavy[u]];
			}
			else
				vec[u] = new vi();

			insert(u);

			for (auto v : g[u])
			{
				if (v.to == u || v.to == heavy[u])
					continue;
				for (auto &x : (*vec[v.to]))
				{
					insert(x);
				}
			}

			if (!keep)
			{
				for (auto v : *vec[u])
				{
					restore(v);
				}
			}
		};

		firstDfs(root, -1);
		secondDfs(root, -1, 1);
	}
};