#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


const long long MOD = 1e9 + 7;
const long long BAD = 1e18 + 1000;

vector<vector<long long> > w;

vector<vector<long long> > mult(vector<vector<long long> > & a, vector<vector<long long> > & b) {
	vector<vector<long long> > res(a.size(), vector<long long>(b[0].size(), BAD));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			for (int k = 0; k < b[0].size(); k++) {
				if (a[i][j] == BAD || b[j][k] == BAD) continue;
				res[i][k] = min(res[i][k], a[i][j] + b[j][k]);
			}
		}
	}
	return res;
}

vector<vector<long long> > mexp(vector<vector<long long> > & v, long long n) {
	if (n == 1) return w;
	vector<vector<long long> > res(v.size(), vector<long long>(v[0].size()));
	res = mexp(v, n / 2);
	res = mult(res, res);
	if (n % 2) {
		res = mult(res, w);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m, k;
	cin >> n >> m >> k;
	w.resize(n);
	for (int i = 0; i < n; i++) {
		w[i].assign(n, BAD);
	}
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cin >> w[x][y];
	}
	vector<vector<long long> > trans = w;
	vector<vector<long long> > expon = mexp(trans, k);
	long long res = BAD;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = min(res, expon[i][j]);
		}
	}
	if (res == BAD) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
