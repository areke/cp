#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> v(n);
	map<long long, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mp[v[i]]++;
	}
	sort(v.begin(), v.end());
	long long res = 0;
	long long val = 0;
	bool found = false;
	for (int i = 0; i < n - 1; i++) {
		int cnt = mp[v[i]];
		int llk = k;
		int rrk = k;
		if (v[i] == v[i + 1]) {
			llk -= cnt - 1;
			rrk--;
		}
		for (int j = 0; j < 4; j++) {
			long long p = v[i] + j;
			if (i > 1 && p == v[i - 1]) continue;
			int lk = llk;
			int rk = rrk;
			if (p > v[i + 1]) break;
			if (v[i] != v[i + 1]) {
				if (p == v[i]) rk--;
				if (p == v[i + 1]) lk-=mp[v[i + 1]];
			}
			long long cur = 0; 
			long long l = 0, r = m;
			if (lk == 0 || rk == 0) {
				l = m + 1;
			} else {
				if (i >= lk - 1 && i + rk < n) {
					l = v[i - (lk - 1)] + ((p - v[i - (lk - 1)]) / 2) + 1;
					r = v[i + rk] - (v[i + rk] - p) / 2 - 1;
				} else if (i >= lk - 1) {
					l = v[i - (lk - 1)] + ((p - v[i - (lk - 1)]) / 2) + 1;
				} else if (i + rk < n) {
					r = v[i + rk] - (v[i + rk] - p) / 2 - 1;
				}
			}
			if (r >= l) {
				cur = r - l + 1;
			}
			
			if (cur > res) {
				res = cur;
				val = p;
			}
		}
		if (v[i] == v[i + 1]) {
			while (i + 1 < n && v[i] == v[i + 1]) i++;
			i--;
		}
 
	}

	if (n < k) {
		cout << m + 1 << " " << 0 << endl;
		return 0;
	}
	long long cur = v[k - 1];
	for (int i = 1; i < 3; i++) {
		long long p = cur - i;
		long long l = 0;
		long long r = m;
		if (p < 0) break;
		if (k > 1 && p <= v[k - 2]) r = p;
		else if (2 * k - 2 < n) {
			r = v[2 * k - 2] - (v[2 * k - 2] - p) / 2 - 1;
		}
		if (r >= l && (r - l + 1 > res || (r - l + 1 == res && p < val))) {
			res = r - l + 1;
			val = p;
		}
	}
	cur = v[n - k];

	for (int i = 1; i < 3; i++) {
		long long p = cur + i;
		long long l = 0;
		long long r = m;
		if (p > m) break;
		if (k > 1 && p >= v[n - k + 1]) l = p;
		else if (n - 2 * k + 1 >= 0) {
			l = v[n - 2 * k + 1] + ((p - v[n - 2 * k + 1]) / 2) + 1;
		}
		if (r >= l && (r - l + 1 > res || (r - l + 1 == res && p < val))) {
			res = r - l + 1;
			val = p;
		}
	}
	cout << res << " " << val << endl;
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}