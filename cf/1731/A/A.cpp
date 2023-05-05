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
		long long s = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s *= a[i];
		}
		long long res = (s + n - 1) * 2022;
		cout << res << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
