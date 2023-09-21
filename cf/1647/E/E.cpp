#include <bits/stdc++.h>
using namespace std;

int LEVELS = 30;
vector<vector<int> > jump(LEVELS, vector<int>(1e5, -1));

// jumps to the dth ancestor of x
// returns the ancestor with the answer on a segment (NOT INCLUDING LAST NODE)
int jmp(int x, int d) {
	int ret = x;
	for (int i = 0; i < LEVELS; i++) {
		if ((1 << i) & d) {
			ret = jump[i][x];
			x = ret;
		}
		if (x == -1) return -1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<int> p(n);
	vector<vector<int> > v(n);
	for (int i = 0; i < n ; i++) {
		cin >> p[i];
		p[i]--;
		v[p[i]].push_back(i);
		v[i].push_back(p[i]);
	}
	vector<int> b(n);
	map<int, int> r;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
	}

	for (int i = 0; i < n; i++) {
		r[p[i]]++;
	}

	int num = 0;
	for (auto it : r) {
		num += it.second - 1;
	}
	int maxi = 0;
	vector<int> a(n, -1);
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, b[i]);
		if (b[i] < n) a[b[i]] = i;
	}
	int turns = (maxi - (n - 1)) / num;
	jump[0] = p;

	for (int i = 1; i < jump.size(); i++) {
		for (int j = 0; j < n; j++) {
			auto old = jump[i - 1][j];
			if (old == -1) continue;
			auto next = jump[i - 1][old];
			jump[i][j] = next;
		}
	}

	map<int, set<int> > m;
	set<int> un;
	vector<int> rev(n);
	for (int i = n - 1; i >= 0; i--) {
		int x = jmp(i, turns);
		if (b[x] >= n) continue;
		m[x].insert(i);
		rev[i] = x;
	}
	vector<int> res(n, -1);

	for (int i = 0; i < n; i++) {
		int f = -1;
		if (a[i] == -1) {
			f = *un.begin();
			res[f] = i;
			un.erase(f);
		} else {
			f = *m[a[i]].begin();
			res[f] = i;
			m[a[i]].erase(f);
			for (auto it : m[a[i]]) un.insert(it);
			m[a[i]].clear();
		}
		//cout << i << " " << a[i] << " " << f << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] + 1 << " \n"[i == n - 1];
	}



	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
