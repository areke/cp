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


vector<vector<long double> > mult(vector<vector<long double> > & a, vector<vector<long double> > & b) {
	vector<vector<long double> > res(a.size(), vector<long double>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[0].size(); j++) {
			for (int k = 0; k < b[0].size(); k++) {
				res[i][k] += a[i][j] * b[j][k];
			}
		}
	}
	return res;
}

vector<vector<long double> > mexp(vector<vector<long double> > & v, long long n) {
	if (n == 0) return {{1, 0}, {0, 1}};
	if (n == 1) return v;
	vector<vector<long double> > res(v.size(), vector<long double>(v[0].size()));
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
	long long n;
	long double p;
	cin >> n >> p;
	// [1 - p, p] [1, 0]
	// [p, 1 - p]
	vector<vector<long double> > cur = {{1}, {0}};
	vector<vector<long double> > trans = {{1 - p, p}, {p, 1-p}};
	vector<vector<long double> > expon = mexp(trans, n);
	cout << fixed << setprecision(9) << mult(expon, cur)[0][0] << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
