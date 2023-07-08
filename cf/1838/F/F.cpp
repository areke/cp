#include <bits/stdc++.h>
using namespace std;


pair<int, int> query(int r, int c, vector<vector<char> > & v) {
	int n = v.size();
	cout << "? " << r + 1 << " " << c + 1 << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		}
		cout << "\n";
	}
	cout.flush();
	int x, y;
	cin >> x >> y;
	return {x - 1, y - 1};
}

pair<int, int> solve(bool r, bool c, vector<vector<char> > & v) {
	int n = v.size();
	int low = 0;
	int high = n * n - 1;
	pair<int, int> best;
	while (low <= high) {
		int mid = (low + high) / 2;
		int x = mid / n;
		int y = mid % n;
		if ((x % 2) && !c) y = n - y - 1;
		if ((x % 2 == 0) && c) y = n - y - 1;
		if (r) x = n - x - 1;
		auto p = query(x, y, v);
		if (p.first == -2) {
			low = mid + 1;
			best = {x, y};
		} else {
			high = mid - 1;
		}
	}
	return best;
	
}

int main() {
	int n;
	cin >> n;
	vector a(n, vector<char>(n));
	vector b(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0) {
				if (j == n - 1) {
					a[i][j] = 'v';
					b[n - i - 1][j] = '^';
				} else {
					a[i][j] = '>';
					b[n - i - 1][j] = '>';
				}
			} else {
				if (j == 0) {
					a[i][j] = 'v';
					b[n - i - 1][j] = '^';
				} else {
					a[i][j] = '<';
					b[n - i - 1][j] = '<';
				}
			}
		}
	}
	if (n % 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i][j] == '>') b[i][j] = '<';
				else if (b[i][j] == '<') b[i][j] = '>';
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				swap(b[i][j], b[i][n - j - 1]);
			}
		}
	}
	auto first = query(0, 0, a);
	pair<int, int> second;
	if (n % 2) {
		second = query(n - 1, n - 1, b);
	} else {
		second = query(n - 1, 0, b);
	}
	pair<int, int> res;
	if (first.first != -2 && second.first != -2) {
		res = first;
		//cout << first.first << " " << first.second << " " << second.first << " " << second.second << endl;
		if (res.first < 0) res.first++;
		if (res.first == n) res.first--;
		if (res.second < 0) res.second++;
		if (res.second == n) res.second--;
	} else if (first.first == -2) {
		res = solve(0, 0, a);
	} else {
		if (n % 2) {
			res = solve(1, 1, b);
		} else {
			res = solve(1, 0, b);
		}
	}


	vector v(n, vector<char>(n, '>'));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != res.first && j != res.second) continue;
			if (i == res.first) {
				if (j < res.second) v[i][j] = '<';
				else v[i][j] = '>';
			} else {
				if (i < res.first) v[i][j] = '^';
				else v[i][j] = 'v';
			}
		}
	}
	auto ans = query(res.first, res.second, v);
	char c;
	if (ans.first == -1) {
		c = '^';
	} else if (ans.first == n) {
		c = 'v';
	} else if (ans.second == -1) {
		c = '<';
	} else {
		c = '>';
	}
	cout << "! " << res.first + 1 << " " << res.second + 1 << " " << c << endl;
	cout.flush();


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
