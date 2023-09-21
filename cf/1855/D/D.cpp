#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION
	
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	bitset<MAXN> b;
	vector<long long> p(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + v[i];
	}
	long long res = v[0];
	b[0] = 1;
	for (int i = 0; i < n; i++) {
		b >>= i;
		int ind = b._Find_first();
		if (ind == MAXN) {
			break;
		}
		res = max(res, p[i + 1] - (ind + i));
		b <<= i;
		b |= (b << v[i]);
	}
	cout << res << endl;

	return 0;
}
