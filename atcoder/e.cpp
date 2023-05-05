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
#include <numeric>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
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

long long modpow(long long a, long long p, long long m) {
	if (p == 0) return 1;
	long long res = modpow(a, p / 2, m);
	res *= res;
	res %= m;
	if (p % 2 == 1) res *= a;
	res %= m;
	return res;
}



long long solve(long long a, long long x, long long m) {
	if (a == 1) {
		return x % m;
	} else {
		// v[0] * (a - 1) + v[1] * m = g
		// (a^x - 1) (mod m * (a - 1))

		// a/g = x mod b

		// a = x mod b * g
		// (a^x - 1) / (a - 1) = y mod M
		// a^X - 1 = y * (a - 1) mod(M * (a- 1))

		// a^x -1 = c*M*(a-1) + b*(a-1) mod (m * (a - 1))
		//        = b * (a - 1) mod(m * (a - 1))

		// 
		
		//
		// a^x - 1 = (cm + y) * (a - 1)
		// (a^x - 1) / g = (cm + y) * (a - 1) / g
		// (a^x - 1) / g = y * (a - 1) / g (mod m)
		// (a^x - 1) / g * v[0] = y * (a - 1) * v[0] / g (mod m)
		// 

		// (a - 1) * v[0] = g mod m
		//(a^x - 1) * v[0] = g * y mod m
		// 
		long long res = modpow(a, x, m * (a - 1)) - 1;
		assert(res % (a -1) == 0);
		res /= (a - 1);
		res %= m;
		return res;
	}
}

long long solve2(long long a, long long x, long long m) {
	long long maxi = 1e18;
	long long res = modpow(a, x, maxi);
	res--;
	if (a - 1 == 0) return x % m;
	res /= (a - 1);
	return res % m;
}

int main() {
	long long a, x, m;
	cin >> a >> x >> m;
	cout << solve(a,x,m)  << endl;
	
	
	


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}