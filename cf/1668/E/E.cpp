#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		cout << "1 1" << endl;
		return 0;
	}
	int x = 1;
	int y = n - 1;
	int cur = 0;
	vector<pair<int, int> > res;
	int dx[2] = {2, 1};
	int dy[2] = {-1, -2};
	while (x >= 1 && y >= 1 && x <= n && y <= n) {
		res.push_back({x, y});
		x += dx[cur];
		y += dy[cur];
		cur ^= 1;
	}
	if (res.back().first != n && res.back().second != 1) {
		res.push_back({n,1});
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
		// INDUCTION

	return 0;
}
