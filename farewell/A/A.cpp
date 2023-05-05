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
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int la, ra, lb, rb;
		cin >> la >> ra >> lb >> rb;
		la--;
		ra--;
		lb--;
		rb--;
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] = p[i] + a[i];
		}
		long long res = 0;
		for (int i = la; i <= ra; i++) {
			long long cur = 1e18;
			// left 
			if (lb < i) {
				int ind = min(i - 1, rb);
				int leftind = (i - ind) / 2;
				cur = min(p[n] - p[i - leftind], cur);
			}
			if (rb > i) {
				int ind = max(i + 1, lb);
				int rightind = (ind - i) / 2;
				cur = min(p[i + rightind + 1], cur);
			}
			res = max(res, cur);
		}
		cout << "Case #" << test << ": " << res << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
