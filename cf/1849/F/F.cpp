#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	vector<pair<long long, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	long long low = 0;
	long long high = 1LL << 32;
	string res = "";
	long long ans = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		string cur(n, '0');
		vector<long long> a(2, -1);
		a[0] = v[0].first;
		int last = 0;
		bool can = true;
		for (int i = 1; i < n; i++) {
			if (v[i].first == a[last] || ((v[i].first ^ a[last]) >= mid)) {
				a[last] = v[i].first;
			} else {
				last ^= 1;
				if (a[last] == -1 || (a[last] ^ v[i].first) >= mid) {
					a[last] = v[i].first;
				} else {
					can = false;
					break;
				}
			}
			//cout << i << " " << v[i] << " " << a[last] << endl;
			cur[v[i].second] = ('0' + last);
		}
		if (can) {
			res = cur;
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << res << endl;
//	cout << res << " " << ans << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
