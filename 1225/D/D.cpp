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

int main() {
	// let a_i = p_0^e_0 * p_1^e_1 * y^k
	// note that y^k has no effect on the answer, so remove all kth powers from a_i
	// let da_i = a_i / y^k
	// then, we look for da_j such that da_j = p_0^(k-e_0) * p_1^(k-e_1), and add to the answer
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	set<int> target;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	set<int> perf;
	int maxi = 1;
	int vmax = 1e5;
	maxi = pow(1e5, 1.0 / k);
	for (int i = 1; i <= maxi; i++) {
		perf.insert(pow(i, k));
	}
	map<int, int> m;
	for (int i = 0; i < v.size(); i++) {
		for (auto j : perf) {
			while (j!= 1 && v[i] % j == 0) v[i] /= j;
		}
		m[v[i]]++;
	}
	long long res = 0;
	for (int i = 0; i < v.size(); i++) {
		vector<int> p(10);
		int pk = 0;
		int x = v[i];
		for (int j = 2; j <= sqrt(v[i]); j++) {
			if (x % j == 0) {
				while (j!=1 && x % j == 0) x /= j;
				if (j != 1) p[pk++] = j;
				int jj = x / j;
				if (jj > 1 && x % (jj) == 0) {
					while (x % jj == 0) x/= jj;
					p[pk++] = jj;
				}
				// cout << x << " " << j << " " << x/j << " " << pk << endl;
			}
			
		}
		if (x > 1) p[pk++] = x;
		int t = 1;
		long long big = pow(1e10, 1.0 / k);
		long long cur = 1;
		bool val = true;
		for (int j = 0; j < pk; j++) {
			cur *= p[j];
			if (cur > big) {
				val = false;
				break;
			}
		}
		if (!val) continue;

		int targ = pow(cur, k) / v[i];
		// cout << i << " " << v[i] << " " << m[v[i]] << " " << targ << " " << m[targ] << " " << cur << endl;
		if (targ == v[i]) {
			res += (long long)m[targ] - 1;
		} else {
			res += (long long)m[targ];
		}
	}
	cout << res / 2 << endl;
	return 0;
}
