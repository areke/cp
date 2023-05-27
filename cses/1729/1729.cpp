#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	vector<int> g(n + 1, 0);
	int s[101] = {0};
	for (int i = 1; i <= n; i++) {
		fill(s, s + k + 1, 0);
		for (int x : v) {
			if (i - x >= 0) {
				s[g[i - x]] = 1;
			}
		}
		int mx = 0;
		for (int j = 0; j <= k; j++) {
			if (!s[j]) {
				mx = j;
				break;
			}
		}
		g[i] = mx;
	}
	string res = "";
	for (int i = 1; i <= n; i++) {
		if (g[i]) res += "W";
		else res += "L";
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
