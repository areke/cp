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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	int n, q;
	cin >> n >> q;
	vector<long long> a(n);
	vector<long long> low(n);
	long long is = 0;

	set<long long> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		is += a[i];
		s.erase(a[i]);
		s.insert(a[i] - i);
		low[i] = *(s.begin());
	}
	for (int qq = 0; qq < q; qq++) {
		long long k;
		cin >> k;
		long long res = 0;
		long long mini, su, sub;
		if (k <= n) {
			mini = low[k - 1] + k;
			if (k < n) {
				mini = min(low[k - 1] + k, a[k]);
			}
			su = is + (k * k) - (k * (k - 1)) / 2;
			sub = 0;
		} else {
			if ((k - n) % 2 == 0) {
				
				mini = low[n - 1] + k;
				sub = (k - n) / 2;
				su = is + (k * n) - (n * (n - 1)) / 2;
				
			} else {
				mini = min(low[n - 2] + k, a[n - 1]);
				su = is + (k * (n - 1)) - ((n - 1) * (n - 2)) / 2;
				sub = (k - (n - 1)) / 2;
				
			}
		}
		if (su - mini * n >= sub) {
			res = mini;
		} else {
			sub = sub - (su - mini * n);
			res = mini - sub / n;
			if (sub % n != 0) res--;
		}
		cout << res << " \n"[qq == q - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
