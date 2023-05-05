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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + b[i];
		}
		vector<long long> s(n + 1, 0);
		vector<long long> res(n, 0);
		for (int i = 0; i < n; i++) {
			int low = i;
			int high = n - 1;
			int b = i - 1;
			while (low <= high) {
				int mid = (low + high) / 2;
				if (p[mid + 1] - p[i] <= a[i]) {
					b = max(b, mid);
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			long long tot = p[b + 1] - p[i];
			if (b + 1 <= n - 1) {
				long long left = a[i] - tot;
				res[b + 1] += left;
			}
			if (b >= i) {
				s[i]++;
				s[b + 1]--;
			}
		}
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			cur += s[i];
			res[i] += cur * b[i];
		}
		assert(cur + s[n] == 0);
		for (int i = 0; i < n; i++) {
			cout << res[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
