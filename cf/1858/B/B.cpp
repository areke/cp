#include <bits/stdc++.h>
using namespace std;

long long get(long long a, long long b, long long div) {
	return (b - a - 1) / div;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, m, d;
		cin >> n >> m >> d;
		vector<long long> s(m);
		for (int i = 0; i < m; i++) {
			cin >> s[i];
		}
		long long res = 1;
		long long last = 1;
		vector<long long> dif;
		long long div = d;
		for (int i = 0; i < m; i++) {
			res += get(last, s[i], div);
			if (s[i] != 1) res++;
			last = s[i];
		}
		res += (n - s[m - 1]) / div;
		for (int i = 1; i < m - 1; i++) {
			long long old = get(s[i - 1], s[i], div) + get(s[i], s[i + 1], div);
			long long nw = get(s[i - 1], s[i + 1], div);
			dif.push_back(nw - old - 1);
		}
		long long old = get(1, s[0], div) + get(s[0], s[1], div);
		long long nw = get(1, s[1], div);
		long long delt = nw - old;
		if (s[0] != 1) delt--;
		dif.push_back(delt);


		old = (n - s[m - 1]) / div + get(s[m - 2], s[m - 1], div);
		nw = (n - s[m - 2]) / div;
		dif.push_back(nw - old - 1);
		sort(dif.begin(), dif.end());
		res += dif[0];
		int ans = 1;
		for (int i = 1; i < dif.size(); i++) {
			if (dif[i] == dif[i - 1]) ans++;
			else break;
		}

		cout << res << " " << ans << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
