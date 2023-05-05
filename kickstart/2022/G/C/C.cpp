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
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> p(n + 1, 0);
		for (int i = 0; i < n; i++) {
			p[i + 1] += p[i] + v[i];
		}
		vector<long long> g(n + 1, 0);
		stack<int> s;
		for (int i = 0; i <= n; i++) {
			while (!s.empty() && p[i] < p[s.top()]) {
				g[s.top()] = i - 1;
				s.pop();
			}
			s.push(i);
		}
		while (!s.empty()) {
			g[s.top()] = n;
			s.pop();
		}
		vector<long long> ps(n + 2, 0);
		for (int i = 0; i <= n; i++) {
			ps[i + 1] += ps[i] + p[i];
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			
			if (v[i] >= 0) {
				//cout << i << " " << g[i] << " " << ps[g[i] + 1] - ps[i] - p[i] * (g[i] - i + 1) << endl;
 				res += max(0LL, ps[g[i] + 1] - ps[i + 1] - p[i] * (g[i] - i));
			}
		}
		cout << "Case #" << test << ": " << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
