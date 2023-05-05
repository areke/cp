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
#include <numeric>
#include <cstring>
using namespace std;


vector<long long> extend_euclid(long long a, long long b) {
	// we know that (1 * a) + (0 * b) = a and (0 * a) + (1 * b) = b
	vector<long long> x = {1, 0, a};
	vector<long long> y = {0, 1, b};

	// run extended Euclidean algo
	while (y[2] > 0) {
		// keep subtracting multiple of one equation from the other
		long long k = x[2] / y[2];
		for (int i = 0; i < 3; i++) {
			x[i] -= k * y[i];
		}
		swap(x, y);
	}
	return x;  // x[0] * a + x[1] * b = x[2], x[2] = gcd(a, b)
}

long long BAD = 1e18;

long long solve(long long dif, long long n, long long d) {
	if (dif < 0) dif += n;
	long long g = gcd(n, d);
	if (dif % g != 0) {
		return BAD;
	}
	n /= g;
	dif /= g;
	d /= g;
	vector<long long> x = extend_euclid(d, n);
	long long inv = x[0] % n;
	if (inv < 0) inv += n;
	long long cur = inv * (-dif);
	cur %= n;
	if (cur <0) cur += n;
	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int w, n, d;
		cin >> w >> n >> d;
		vector<long long> a(w);
		for (int i = 0; i < w; i++) {
			cin >> a[i];
		}
		long long res = 0;
		bool can = true;
		for (int i = 0; i < w / 2; i++) {
			long long dif = (a[i] - a[w - i - 1]);
			if (dif < 0) dif += n;
			long long cur = solve(dif, n, d);
			dif = (a[w - i - 1] - a[i]);
			if (dif < 0) dif += n;
			cur = min(cur, solve(dif, n , d));
			if (cur == BAD) {
				can = false;
				break;
			}
			res += cur;
			// x[0] * d + x[1] * n = 1
			// (x[0] % n)

			// x[0] * d + x[1] * n = 1
			// dif + dx = 0 (mod n)
			// n and d are relatively prime, always pos

			// dx = -dif (mod n)
			// x = x[0] * -dif
			// dif 
			// x[0] is an inverse of d
		}
		if (!can) {
			cout << "Case #" << test <<": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << test <<": " << res << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
