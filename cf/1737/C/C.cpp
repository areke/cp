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
#include <queue>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

bool in_bound(long long n, long long x, long long y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

bool has_diag(long long n, vector<long long> a, vector<long long> b) {
	long long x = b[0] - a[0];
	long long y = b[1] - a[1];
	if (abs(x) == 0 || abs(y) == 0) return false;
	if (in_bound(n, b[0] + x, a[1] + y)) {
		return true;
	}
	if (in_bound(n, a[0] - x, b[1] - y) ){
		return true;
	}
	return false;

}

bool is_corner_square(long long n, vector<long long> v) {
	if (v[0] == 1 && v[1] == 1) return true;
	if (v[0] == 1 && v[1] == n) return true;
	if (v[0] == n && v[1] == 1) return true;
	if (v[0] == n && v[1] == n) return true;
	return false;
}

bool is_corner(long long n, vector<vector<long long>> & v) {
	for (int i = 0; i < 3; i++) {
		if (is_corner_square(n, v[i])) return true;
	}
	return false;
}

vector<long long> get_rep(vector<vector<long long> > & v) {
	for (int i = 0; i < 3; i++) {
		bool b = true;
		for (int j = 0; j < 3; j++) {
			if (v[i][0] != v[j][0] && v[i][1] != v[j][1]) {
				b = false;
				break;
			}
		}
		if (b) return v[i];
		
	}
	assert(0 == 1);

}

bool solve(long long n, vector<vector<long long> > & v, long long x, long long y) {
	sort(v.begin(), v.end());
	vector<long long> rep = get_rep(v);
	if (is_corner_square(n, rep)) {
		return x == rep[0] || y == rep[1];
	}
	return x % 2 == rep[0] % 2 || y % 2 == rep[1] % 2;
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		vector<vector<long long> > v;
		for (int i = 0; i < 3; i++) {
			vector<long long> vv(2);
			for (int j = 0; j < 2; j++) {
				cin >> vv[j];
			}
			v.push_back(vv);
		}
		long long x, y;
		cin >> x >> y;
		if (solve(n, v, x, y)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
