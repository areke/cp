#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> pos(n + 1, 0);
	vector<long long> neg(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			pos[i + 1] = pos[i] + a[i];
			neg[i + 1] = neg[i] + a[i];
		} else {
			pos[i + 1] = pos[i] + k;
			neg[i + 1] = neg[i] - k;
		}
	}
	bool can = false;
	long long slack = 0;
	long long tot = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) tot += a[i];
		else slack++;
	}
	if (abs(tot) <= slack * k) can = true;
	if (!can) {
		cout << -1 << endl;
		return 0;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			
			if (i < j) {
				long long up = pos[i + 1] + pos[n] - pos[j + 1];
				if (up < 0) continue;
				long long down = neg[j + 1] - neg[i + 1];
				if (down > 0) continue;
				res = max(res, min(up, abs(down)));
			} else {
				swap(i, j);
				long long down = neg[i + 1] + neg[n] - neg[j + 1];
				long long d1 = neg[i + 1];
				long long d2 = neg[n] - neg[j + 1];
				long long up = pos[j + 1] - pos[i + 1];
				//cout << i << " " << j << " " << d1 <<" " << d1 << " " << up << endl;
				swap(i, j);
				if (down > 0) continue;
				
				if (up < 0) continue;
				res = max(res, min(up, abs(down)));
			}
		}
	}
	cout << res + 1 << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
