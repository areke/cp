#include <bits/stdc++.h>
using namespace std;


/**
 * Short for "binary indexed tree",
 * this data structure supports point update and range sum
 * queries like a segment tree.
 * */
template <class T> class BIT {
  private:
	int size;
	int bit[1001] = {0};
	int arr[1001] = {0};

  public:
	BIT(int size) : size(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, int val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, int val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(n, 0));
	vector<BIT<int> > p(n, BIT<int>(n + 1));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '*') v[i][j] = 1;
			else v[i][j] = 0;

			p[i].set(j + 1, v[i][j]);
		}
	}
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			v[x][y] ^= 1;
			p[x].set(y + 1, v[x][y]);
		} else if (t == 2) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--;
			b--;
			c--;
			d--;
			long long res = 0;
			for (int j = a; j <= c; j++) {
				res += p[j].pref_sum(d + 1) - p[j].pref_sum(b);
			}
			ans.push_back(res);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}