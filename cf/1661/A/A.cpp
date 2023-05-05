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
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		long long res = 0;
		for (int i = 1; i < n; i++) {
			long long s = abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
			swap(a[i], b[i]);
			s = min(s, abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]));
			res = res + s;
		}
		cout << res << endl;
		
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
