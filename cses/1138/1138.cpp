#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
#include <functional>

using namespace std;


using ll = long long;

using pii = pair<int, int>;
#define mp make_pair
#define xx first
#define yy second

#define pb emplace_back
#define sz(x) int(x.size())

const int INF = 1e9 + 5;

// T is a monoid and U are endomorphisms (T -> T)
template <typename T, typename U>
struct lazy_seg_t {
  struct internal_node {
    T x;
    U f;
    bool stale;
  };

  int n, k, height;
  T zero;
  U noop;

  vector<internal_node> tree;

  explicit lazy_seg_t(int n, T zero = T(), U noop = U())
    : n(n), zero(zero), noop(noop), tree(4 * n) {
    k = 1, height = 1;
    while (k < n)
      k <<= 1, ++height;
  }

  void build(std::vector<T> const& arr) {
    assert(sz(arr) == n);
    for (int i = 0; i < n; ++i)
      tree[i + k].x = arr[i];

    for (int i = k - 1; i > 0; --i)
      tree[i].x = tree[2 * i].x + tree[2 * i + 1].x;
  }

  void apply(int i, U const& f) {
    tree[i].x = f(tree[i].x);
    if (i < k) {
      tree[i].f = tree[i].f + f;
      tree[i].stale = true;
    }
  }

  void rebuild(int i) {
    for (int u = i / 2; u; u /= 2) {
      T comb = tree[2 * u].x + tree[2 * u + 1].x;
      tree[u].x = tree[u].f(comb);
    }
  }

  void propagate(int i) {
    for (int h = height; h > 0; --h) {
      int u = i >> h;
      if (tree[u].stale) {
        apply(2 * u, tree[u].f);
        apply(2 * u + 1, tree[u].f);
        tree[u].f = noop;
        tree[u].stale = false;
      }
    }
  }

  void update(int i, int j, U const& u) {
    i += k, j += k;
    propagate(i), propagate(j);

    for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
      if ((l & 1) == 1) apply(l++, u);
      if ((r & 1) == 0) apply(r--, u);
    }

    rebuild(i), rebuild(j);
  }

  T query(int i, int j) {
    i += k, j += k;
    propagate(i), propagate(j);

    T l = zero, r = zero;
    for (; i <= j; i /= 2, j /= 2) {
      if ((i & 1) == 1) l = l + tree[i++].x;
      if ((j & 1) == 0) r = tree[j--].x + r;
    }

    return l + r;
  }
};

struct node_t {
  ll x;

  node_t operator+(node_t const& other) {
    return { x + other.x };
  }
};

struct update_t {
  ll x;

  node_t operator()(node_t const& node) const {
    return { node.x + x };
  }

  update_t operator+(update_t const& u) {
    return { x + u.x };
  }
};

void solve(int x, vector<vector<int> > & v, vector<long long> & a, vector<long long> & dp, int last) {
	if (last == -1) dp[x] = a[x];
	else dp[x] = dp[last] + a[x];
	for (int n : v[x]) {
		if (n == last) continue;
		solve(n, v, a, dp, x);
	}
}


const int LEVELS = 19;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> p(n, -1);
	vector<vector<int > > v(n);
	lazy_seg_t<node_t, update_t> seg(n);
	vector<long long> a(n);
	vector<long long> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	solve(0, v, a, dp, -1);

	vector<vector<int > > jump(LEVELS, vector<int >(n, -1));
		
	vector<pair<int, int> > d(n);
	int cnt = 0;
	// populate jump[i] with the 2^0th ancestor of i, and d with the euler
	vector<int> ee(n, 0);
	function<void (int x, int & cnt, int last)> dfs = [&](int x, int & cnt, int last) {
		jump[0][x] = last;
		ee[x] = cnt;
		int s = cnt;
		for (auto n : v[x]) {
			if (n == last) continue;
			dfs(n, ++cnt, x);
		}
		int e = cnt;
		d[x] = {s, e};
	};
	dfs(0, cnt, -1);
	for (int i = 0; i < n; i++) {
		seg.update(ee[i], ee[i], {dp[i]} );
	}
	

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int s, x;
			cin >> s >> x;
			s--;
			long long delta = x - a[s];
			a[s] = x;
			seg.update(d[s].first, d[s].second, { delta } );
			
		} else {
			int s;
			cin >> s;
			s--;
			cout << seg.query(ee[s], ee[s]).x << endl;
		}
	}







	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
