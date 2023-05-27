#include <bits/stdc++.h>
using namespace std;

/**
 * Description: Modular arithmetic.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; cout << (int)inv(a); // 400000003
 */


vector<vector<long long> > ID;

long long INF = 2e18;

vector<vector<long long> > mult(vector<vector<long long> > & a, vector<vector<long long> > & b) {
	vector<vector<long long> > res(a.size(), vector<long long>(b[0].size(), INF));
	assert(b.size() == a[0].size());
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			for (int k = 0; k < b[0].size(); k++) {
				res[i][k] = min(a[i][j] + b[j][k], res[i][k]);
			}
		}
	}
	return res;
}

vector<vector<long long> > mexp(vector<vector<long long> > & v, long long n) {
	assert(v.size() == v[0].size());
	if (n == 0) {
    assert(1 == 0);
  }
	if (n == 1) return v;
	vector<vector<long long> > res(v.size(), vector<long long>(v[0].size()));
	res = mexp(v, n / 2);
	res = mult(res, res);
	if (n % 2) {
		res = mult(res, v);
	}
	return res;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	long long n, m, k;
	cin >> n >> m >> k;
	vector<vector<long long> > mat(n, vector<long long>(n, INF));

	ID = vector<vector<long long> >(n, vector<long long>(n, 0));
	for (int i = 0; i < n; i++) {
		ID[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i) assert(ID[i][j] == 1);
			else assert(ID[i][j] == 0);
		}
	}
	for (int i = 0; i < m; i++) {
		long long x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		mat[x][y] = min(mat[x][y], w);
	}
	auto x = mexp(mat, k);
	if (x[0][n - 1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	cout << x[0][n - 1] << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
