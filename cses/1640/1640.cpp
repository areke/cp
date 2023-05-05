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
	long long n, x;
	cin >> n >> x;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	map<long long, int> m;
	long long resa = -1, resb = -1;
	for (int i = 0; i < n; i++) {
		if (m[x - v[i]]) {
			resa = m[x - v[i]];
			resb = i;
		}
		m[v[i]] = i + 1;
	}
	if (resa == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << resa << " " << resb + 1 << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
