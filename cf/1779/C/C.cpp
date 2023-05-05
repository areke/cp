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
		// prefix sums after m + 1 to n must be nonnegative
		// a[m] must be nonnegative
		// s(a1, ax) >= s(a1, am)
		// s(ax+1, am) <= 0
		int n, m;
		cin >> n >> m;
		m--;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long res = 0;
		long long s = 0;
		priority_queue<long long> pq;
		for (int i = m + 1; i < n; i++) {
			s += a[i];
			pq.push(-a[i]);
			if (s < 0) {
				//cout << i << " " << s << endl;
				long long t = pq.top();
				pq.pop();
				s += 2 * t;
				res++;
			}
		}
		pq = priority_queue <long long>();
		s = 0;
		for (int i = m; i >= 1; i--) {
			s += a[i];
			pq.push(a[i]);
			if (s > 0) {
				//cout << i << " " << s << endl;
				long long t = pq.top();
				pq.pop();
				s -= 2 * t;
				res++;
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
