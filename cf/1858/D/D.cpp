#include <bits/stdc++.h>
using namespace std;

int lft[3005][3005];
int rght[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int cc = 0;
		int dd = 0;
		for (int i = 0; i <= n + 2; i++) {
			for (int j = 0; j <= n + 2; j++) {
				lft[i][j] = 0;
				rght[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') cc++;
			else {
				cc = 0;
			}
			dd = max(dd, cc);
		}
		
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = i; j < n ; j++) {
				cnt += s[j] - '0';
				int len = j - i + 1;
				int o = cnt;

				lft[j + 1][o] = max(lft[j + 1][o], len);
				rght[i + 1][o] = max(rght[i + 1][o], len);
			}
		}


		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (i > 0) {
					lft[i][j] = max(lft[i][j], lft[i - 1][j]);
				}
				if (j > 0) {
					lft[i][j] = max(lft[i][j], lft[i][j - 1]);
				}
			}
		}
		for (int i = n; i >= 0; i--) {
			for (int j = 0; j <= n; j++) {
				rght[i][j] = max(rght[i][j], rght[i + 1][j]);
				if (j > 0) {
					rght[i][j] = max(rght[i][j], rght[i][j - 1]);
				}
			}
		}
		long long BAD = -1e9;
		vector<long long> b(n + 1, BAD);
		b[0] = max(lft[n][k], rght[0][k]);

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = i; j < n; j++) {
				int len = j - i + 1;
				cnt += s[j] - '0';
				int o = cnt;
				int f = len - o;
				int l = k - f;
				if (l < 0) continue;
				long long best = max(lft[i][l], rght[j + 2][l]);
				b[len] = max(b[len], best);
			}
		}
		vector<long long> res(n, 0);
		for (long long i = 1; i <= n; i++) {
			for (long long j = 0; j <= n; j++) {
				if (b[j] != BAD) {
					res[i - 1] = max(res[i - 1], 1LL * i * b[j] + j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
