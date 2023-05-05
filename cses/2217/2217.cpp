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
#include <unordered_map>
#include <assert.h>
#include <array>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]] = i;
	}
	int res = 1;
	for (int i = 1; i < n; i++) {
		if (m[i] > m[i + 1]) {
			res++;
		}
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		int cur = 0;
		set<int> cand = {v[x], v[x] - 1, v[y], v[y] - 1};
		for (int k : cand) {
			if (k < n && k > 0 && m[k] > m[k + 1]) cur++;
		}
		swap(v[x], v[y]);
		swap(m[v[x]], m[v[y]]);
		int aft = 0;
		for (int k : cand) {
			if (k < n && k > 0 && m[k] > m[k + 1]) aft++;
		}
		res += (aft - cur);
		cout << res << "\n";
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
