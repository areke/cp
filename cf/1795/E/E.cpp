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



vector<long long> solve(vector<long long> & h, int n) {
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = h[i] + i;
	}
	vector<long long> g(n);
	vector<long long> f(n);
	
	stack<long long> s;
	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[i] < a[s.top()]) {
			f[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		f[s.top()] = n;
		s.pop();
	}
	vector<long long> res(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		long long sub = 0;
		if (h[i] - (f[i] - i) >= 0) {
			sub = (h[i] - (f[i] - i)) * (h[i] - (f[i] - i) + 1) / 2;
		}
		res[i] = res[f[i]] + (h[i] * (h[i] + 1) / 2) - sub;
	}
	res.pop_back();
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	int tottests = tests;
	int cnt = 0;
	while (tests--) {
		cnt++;
		int n;
		cin >> n;
		vector<long long> h(n);
		
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		vector<long long> a = solve(h, n);
		reverse(h.begin(), h.end());
		vector<long long> b = solve(h, n);
		//cout << "----" << endl;
		reverse(b.begin(), b.end());
		reverse(h.begin(), h.end());
		
		long long tot = 0;
		for (int i = 0; i < n; i++) {
			tot += h[i];
		}
		long long res = 1e18;
		for (int i = 0; i < n; i++) {
			//cout << i<< endl;
			//cout << a[i] << " " << b[i] << " " << a[i] + b[i] - h[i] << endl;
			long long cur = a[i] + b[i] - h[i];
			//cout << i << " " << tot << " " << cur << " " << h[i] << endl;
			res = min(tot - cur + h[i], res);
		}
		cout << res << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
