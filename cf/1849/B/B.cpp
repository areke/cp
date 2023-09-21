#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k;
		cin >> n >> k;
		priority_queue<pair<long long, int> > pq;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > k) a[i] %= k;
			if (a[i] == 0) a[i] = k;
			pq.push({a[i], -i});
		}
		vector<int> res;
		while (!pq.empty()) {
			auto t = pq.top();
			pq.pop();
			t.first -= k;
			if (t.first <= 0) {
				res.push_back(-t.second);
			}	 else {
				assert(0);
				pq.push(t);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] + 1 << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
