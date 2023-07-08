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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n);

		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<pair<long long, int> > v(n);

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			v[i] = {a[i], i};
		}
		sort(v.begin(), v.end());
		sort(b.begin(), b.end());
		vector<long long> c(n);
		for (int i = 0; i < n; i++) {
			c[v[i].second] = b[i];
		}
		for (int i = 0; i < n; i++) {
			cout << c[i] << " \n"[i == n - 1];
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
