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
		int n, s, r;
		cin >> n >> s >> r;
		vector<int> v(n, 1);
		r = s- r;
		int cur = n + r - 1;
		v[0] = r;
		for (int i = 1; i < v.size(); i++) {
			v[i] = min(r, v[i] + s - cur);
			cur += v[i] - 1;
		}
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
