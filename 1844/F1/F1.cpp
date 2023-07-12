#include <bits/stdc++.h>
using namespace std;

long long score(int x, int y, vector<long long> & v, long long c) {
	if (x >= v.size() || x < 0 || y >= v.size() || y < 0) return 0;
	return abs(v[x] - v[y] - c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, c;
		cin >> n >> c;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		if (c >= 0) {
			for (int i = 0; i < n; i++) {
				cout << v[i] << " \n"[i == n - 1];
			}	
			continue;
		}
		reverse(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			sort(v.begin() + i, v.end(), greater<long long>());
			for (int j = n - 1; j >= i + 1; j--) {
				long long cur = score(j, i - 1, v, c);
				cur += score(i, j, v, c);
				cur += score(j + 1, j - 1, v, c);
				cur -= score(i, i - 1, v, c);
				cur -= score(j, j - 1, v, c);
				cur -= score(j + 1, j, v, c);
				assert(cur >= 0);
				if (cur == 0) {
					swap(v[i], v[j]);
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << v[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
	return 0;
}
