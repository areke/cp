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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<int> l(n, 0);
		vector<int> r(n, 0);
		l[0] = v[0];
		r[n - 1] = v[n - 1];
		for (int i = 1; i < n; i++) {
			l[i] = max(l[i - 1], v[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			r[i] = max(r[i + 1], v[i]);
		}
		string res = "YES";
		for (int i = 1; i < n - 1; i++) {
			if (v[i] < l[i - 1] && v[i] < r[i + 1]) {
				res = "NO";
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
