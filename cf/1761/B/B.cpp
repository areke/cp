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

void erase(int x, vector<int> & a, int & k) {
	int cur = 0;
	for (int i = 0; i < k; i++) {
		if (i == x) continue;
		a[cur] = a[i];
		cur++;
	}
	k--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		if (n <= 2) {
			cout << n << endl;
			continue;
		}
		if (s.size() > 2) {
			cout << n << endl;
		} else {
			cout << n / 2 + 1 << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
