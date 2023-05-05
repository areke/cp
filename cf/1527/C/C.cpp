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
		int n;
		cin >> n;
		map<int, long long> m;
		map<int, long long> c;

		map<int, int> l;
		vector<int> v(n);
		long long res = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long count = 0;
		for (int i = 0; i < n; i++) {
			c[v[i]] += m[v[i]];
			res += c[v[i]] * (n - i);
			m[v[i]]++;
		}
		cout << res << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
