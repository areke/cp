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
long long BAD = 1e18;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		priority_queue<long long> pq;
		long long cur = 0;
		vector<long long> l(n);
		vector<long long> r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		long long res = BAD;
		long long maxi = 0;
		for (int i = 0; i < n; i++) {
			long long d = r[i] - l[i] + 1;
			if (cur < k) {
				pq.push(-d);
				cur += d;
			} else {
				long long low = -pq.top();
				if (d > low) {
					cur += d - low;
					pq.pop();
					pq.push(-d);
				}
			}
			if (cur >= k) {
				while (!pq.empty()) {
					long long x = -pq.top();
					if (cur - x < k) {
						break;
					}
					maxi = max(l[i], r[i] - (cur - k));
					long long val = 2 * pq.size() + maxi;
					res = min(res, val);
					cur -= x;
					pq.pop();
				}
				maxi = max(l[i], r[i] - (cur - k));
				long long val = 2 * pq.size() + maxi;
				res = min(res, val);
				
			}
		}
		if (res == BAD) {
			cout << -1 << endl;
		} else {
			cout << res << endl;
		}
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}