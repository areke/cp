
struct DSUrb {
	int comp = 0;
	vector<int> e; void init(int n) { e = vector<int>(n,-1); comp = n; }
	int get(int x) { return e[x] < 0 ? x : get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	vector<array<int,5> > mod;
	bool unite(int x, int y) { // union-by-rank
		x = get(x), y = get(y); 
		if (x == y) { mod.push_back({-1,-1,-1,-1, 0}); return 0; }
		if (e[x] > e[y]) swap(x,y);
		comp--;
		mod.push_back({x,y,e[x],e[y], 1});
		e[x] += e[y]; e[y] = x; return 1;
	}
	int components() {
		return comp;
	}
	void rollback() {
		auto a = mod.back(); mod.pop_back();
		comp += a[4];
		if (a[0] != -1) e[a[0]] = a[2], e[a[1]] = a[3];
	}
};