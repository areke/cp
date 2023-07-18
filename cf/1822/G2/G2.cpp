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
		long long res = 0;
		set<long long> s;
		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
			s.insert(a[i]);
		}
		for (long long x : s) {
			long long bord = min(MAXI / x, (long long)sqrt(x) + 1);
			
			for (long long b = 1; b <= bord; b++) {
				if (x % b == 0) {
					if (b != 1 && m.count(x / b) && m.count(x * b)) {
						res += m[x / b] * m[x] * m[x * b];
					}
					if (x / b != 1 && x / b > bord) {
						if (m.count(b) && m.count(x / b * x)) {
							res += m[b] * m[x] * m[x * x / b];
						}
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