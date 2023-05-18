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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int qq = 0; qq < q; qq++) {
		long long k;
		cin >> k;
		long long res = 0;
		vector<long long> b = a;
		if (k <= n) {
			for (int i = 0; i < k; i++) {
				b[i] += k - i;
			}
			sort(b.begin(), b.end());
			res = b[0];
		} else {
			long long sub;
			if ((k - n) % 2 == 0) {
				for (int i = 0; i < n; i++) {
					b[i] += k - i;
				}
				sub = (k - n) / 2;
				
			} else {
				for (int i = 0; i < n - 1; i++) {
					b[i] += k - i;
				}
				sub = (k - (n - 1)) / 2;
				
			}
			sort(b.begin(), b.end());
			for (int i = n - 1; i >= 0; i--) {
				sub -= (b[i] - b[0]);
				b[i] = b[0];
			}

			if (sub <= 0) {
				res = b[0];
			} else {
				b[0] -= sub / n;
				if (sub % n != 0) b[0]--;
				res = b[0];
			}
		}
		cout << res << " \n"[qq == q - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
