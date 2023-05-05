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
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> c(m);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> c[i];
		}
		vector<int> v(n + 1, 0);
		for (int i = 0; i < n; i++) {
			v[a[i]]++;
		}

		priority_queue<int> pq;
		for (int i = 0; i <= n; i++) {
			pq.push(v[i]);
		}
		int cur = m - 1;
		int res = 0;
		sort(c.begin(), c.end());
		while (!pq.empty() && cur >= 0) {
			int t = pq.top();
			pq.pop();
			res += min(t, c[cur]);
			t -= min(t, c[cur]);
			pq.push(t);
			cur--;
		}
		cout << res << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
