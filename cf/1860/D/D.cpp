#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > get(string & s, char c) {
	int n = s.length();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (s[i] == c) {
			v.push_back(i);
		}
 	}
	vector<vector<int> > dp(s.size() + 1, vector<int>(10001, 0));
	dp[0][0] = 1;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 10000; j >= 0; j--) {
			for (int k = 0; k < v.size(); k++) {
				if (dp[k][j] && j + v[i] <= 10000) {
					dp[k + 1][j + v[i]] = 1;
				}
			}
			
		}
	}
	return dp;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		int n = s.length();
		int o = 0;
		int z = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (s[i] == '1' && s[j] == '0') {
					o++;
				}
				if (s[i] == '0' && s[j] == '1') {
					z++;
				}
			}
		}

		if (o == z) {
			cout << 0 << endl;
			return 0;
		}
		if (z > o) {
			for (int i = 0; i < n; i++) {
				if (s[i] == '1') s[i] = '0';
				else s[i] = '1';
			}
			swap(o, z);
		}

		int need = (o - z) / 2;
		vector<int> res(need + 1, 1e9);
		res[0] = 0;
		auto a = get(s, '0');
		auto b = get(s, '1');
		int ans = 1e9;
		for (int i = n; i >= 0; i--) {
			for (int j = 0; j <= 10000; j++) {
				if (need + j > 10000) break;
				if (b[i][j] && a[i][need + j]) {
					ans = i;
				}
			}
		}
		cout << ans << endl;


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
