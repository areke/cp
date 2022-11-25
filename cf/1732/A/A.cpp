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
#include <list>
#include <cstring>
using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}


void solve(vector<long long> & a, vector<long long> & v, int cur, int n, int & res) {
	if (a.size() == v.size()) {
		long long g = v[0];
		for (int i = 0; i < v.size(); i++) {
			g = gcd(g, v[i]);
		}
		if (g == 1) {
			res = min(res, cur);
		}
		return;
	}
	if (cur >= n) {
		return;
	}
	v.push_back(a[v.size()]);
	solve(a, v, cur, n, res);
	v[v.size() - 1] = gcd(v[v.size() - 1], v.size());
	solve(a, v, cur + n - v.size() + 1, n, res);
	v.pop_back();
	
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> v;
		int res = n;
		solve(a, v, 0, n, res);
		cout << res << endl;
		
	}
	return 0;
}
