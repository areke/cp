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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	vector<vector<long long> > f(300001);
	for (int i = 2; i <= 300000; i++) {
		if (f[i].size()) continue;
		for (int j = i; j <= 300000; j+=i) {
			f[j].push_back(i);
		}
	}
	while (tests--) {
		long long n;
		cin >> n;
		vector<long long> v(n);
		vector<long long> a(300001, 0);
		vector<long long> b(300001, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		long long res = n * (n - 1) * (n - 2) / 6;
		long long cur = 0;
		vector<long long> (n, 0);
		for (int i = 0; i < v.size(); i++) {
			for (long long k : f[v[i]]) {
				b[k]++;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			res -= cur;
			for (long long k : f[v[i]]) {
				long long m = 1;
				if (f[v[i]].size() % 2 == 0) m = -1;
				cur -= m * a[k] * b[k];
				a[k]++;
				b[k]--;
				cur += m * a[k] * b[k];
			}
			
		}
		cout << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
