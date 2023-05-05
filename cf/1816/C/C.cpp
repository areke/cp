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
bool can(vector<long long> v) {
	int n = v.size();
	bool b = true;
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) {
			if (i == n - 1) {
				b = false;
				break;
			}
			long long dif = v[i - 1] - v[i];
			v[i - 1] -= dif;
			v[i + 1] += dif;
		}
	}
	for (int i = 1; i < n; i++) {
		if (v[i] < v[i - 1]) b = false;
	}
	return b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<long long> ok(2, 0);
		int p = 0;
		for (int i = n - 1; i >= 0; i--) {
			ok[p] += v[i];
			p ^= 1;
		}
		if (ok[0] >= ok[1]) {
			cout << "YES" << endl;
		} else {
			if (n % 2 == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
