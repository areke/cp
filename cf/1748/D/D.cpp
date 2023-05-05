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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long a, b, d;
		cin >> a >> b >> d;
		long long oa = a;
		long long ob = b;
		long long od = d;
		bool can = true;
		long long y = 1;
		while (d % 2 == 0) {
			y *= 2;
			d /= 2;
		}
		if (a % y != 0 || b % y != 0) {
			cout << -1 << endl;
			continue;
		}
		a /= y;
		b /= y;
		long long left = (a | b);
		long long len = 0;
		long long shift = 1;
		shift = shift << 30;
		long long res = left * y;
		if (left % d != 0) {
			long long need = -(left * y % d) + d;
			long long MOD = d;
			vector<long long> e = extend_euclid(shift, MOD);
			e[0] = (e[0] + MOD * shift) % MOD;
			res = (e[0] * need) % MOD;
			//cout << y << " " << left << " " << need << " " << res << " " << e[0] << endl;
			// left + x * 2^30 = 0 (MOD D)
			// x * 2^30 = D - left(MOD D)
			// x = (D - left) * modinv(2^30)
			assert(res > 0);
			res *= shift;
			assert(res % MOD == need);
			assert(res + (oa | ob) == (res | (oa | ob)));

			res |= (oa | ob);

		} else {
			assert(res % od == 0);
		}
		assert((res | oa) == res);
		assert((res | ob) == res);
		cout << res << endl;
	}
	return 0;
}
