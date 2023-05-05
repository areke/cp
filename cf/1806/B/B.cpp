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
		// if z <= n / 2  + n%2, res = 0
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, int> m;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		if (m[0] <= (n / 2) + (n % 2)) {
			cout << 0 << endl;	
		} else if (m[0] == n) {
			cout << 1 << endl;
		} else if (m[0] + m[1] == n) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
