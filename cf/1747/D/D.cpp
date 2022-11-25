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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n, q;
	cin >> n >> q;
	long long bad = 1e10;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> xora(n + 1, 0);
	for (int i = 0; i < n; i++) {
		xora[i + 1] = xora[i] ^ a[i];
	}
	vector<long long> suma(n + 1, 0);
	for (int i = 0; i < n; i++) {
		suma[i + 1] = suma[i] + a[i];
	}
	vector<long long> zeros;
	vector<map<long long, vector<long long> >> m(2);
	for (int i = 0; i <= n; i++) {
		m[i % 2][xora[i]].push_back(i);
	}
	for (int i = 0; i < q; i++) {
		long long l, r;
		cin >> l >> r;
		l--;
		//cout << i << " " << l << " " << r << " " << xora[r] << " " << xora[l] << endl;
		if ((xora[r] ^ xora[l]) != 0) {
			//cout << i << " " << l << " " << r << " " << xora[r] << " " << xora[l] << " " << (xora[r] ^ xora[l]) << endl;
			cout << -1 << endl;
			continue;
		}
		//cout << i << " " << xora[r] << " " << xora[l] << endl;
		long long len = r - l;
		long long res = bad;
		if ((suma[r] - suma[l]) == 0) {
			res = 0;
			cout << res << endl;
			continue;
		}
		if (len % 2 == 1) {
			res = min(res, (long long)1);
		}
		if (len % 2 == 0 && len > 2) {
			// lhs
			auto it = lower_bound(m[(l % 2) ^ 1][xora[l]].begin(), m[(l % 2) ^ 1][xora[l]].end(), l);
			if (it != m[(l % 2) ^ 1][xora[l]].end()) {
				if (*it <= r) {
					res = min(res, (long long)2);
					if (suma[*it] - suma[l] == 0) {
						res = min(res, (long long) 1);
					}
				}
			}
 
			// rhs
			auto it2 = lower_bound(m[(r % 2) ^ 1][xora[r]].rbegin(), m[(r % 2) ^ 1][xora[r]].rend(), r, greater<>());
			if (it2 != m[(r % 2) ^ 1][xora[r]].rend()) {
				if (*it2 >= l) {
					res = min(res, (long long)2);
					if (suma[r] - suma[*it2] == 0) {
						res = min(res, (long long) 1);
					}
				}
			}
 
 
		}
		if (res == bad) res = -1;
		cout << res << endl;
	}
	return 0;
}