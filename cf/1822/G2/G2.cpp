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
#include <unordered_map>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
 
long long MAXI = 1e9;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<long long> a(n);
		set<long long> s;
		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			s.insert(a[i]);
		}
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		long long res = 0;
		if (a.size() <= 5000) {
			for (int i = 0; i < a.size(); i++) {
				for (int j = i + 1; j < a.size(); j++) {
					if (a[j] != a[i] && a[j] % a[i] == 0) {
						long long b = a[j] / a[i];
						if (m.count(b * a[j])) {
							res += m[b * a[j]] * m[a[j]] * m[a[i]];
						}
					}
				}
			}
		} else {
			for (long long b = 2; b <= sqrt(MAXI) + 1; b++) {
				// x, x*b, x*b^2
				for (long long x : s) {
					if (x * b * b > MAXI) break;
					if (m.count(x * b) && m.count(x * b * b)) {
						res += m[x] * m[x * b] * m[x * b * b];
					}
					
				}
			}
			
		}
		for (auto it : m) {
			if (it.second >= 3) {
				res += it.second * (it.second - 1) * (it.second - 2);
			}
		}
		
		cout << res << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}