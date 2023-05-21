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


vector<int> op(vector<int> p, int l, int r) {
	vector<int> a;
	vector<int> b;
	vector<int> c;
	for (int i = 0; i < l; i++) {
		a.push_back(p[i]);
	}
	for (int j = l; j <= r; j++) {
		b.push_back(p[j]);
	}
	for (int i = r + 1; i < p.size(); i++) {
		c.push_back(p[i]);
	}
	reverse(b.begin(), b.end());
	vector<int> ret(c.begin(), c.end());
	for (int i = 0; i < b.size(); i++) {
		ret.push_back(b[i]);
	}
	for (int i = 0; i < a.size(); i++) {
		ret.push_back(a[i]);
	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int maxi = n;
		if (p[0] == n) maxi--;
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (p[i] == maxi) {
				ind = i;
				break;
			}
		}
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			res[i] = i + 1;
		}
		for (int i = ind - 1; i >= 0; i--) {
			auto v = op(p, i, ind - 1);
			bool greater = false;
			for (int j = 0; j < n; j++) {
				if (v[j] != res[j]) {
					if (v[j] > res[j]) greater = true;
					break;
				}
			}
			if (greater) res = v;
		}
		for (int i = ind; i; i++) {
			if (ind < 0 || ind >= n) break;
			auto v = op(p, i, i);
			bool greater = false;
			for (int j = 0; j < n; j++) {
				if (v[j] != res[j]) {
					if (v[j] > res[j]) greater = true;
					break;
				}
			}
			if (greater) res = v;
			break;
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
