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
		long long n;
		long long x;
		cin >> n;
		vector<long long> a(n - 1);
		cin >> x;
		for (int i = 0; i<  n - 1; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n-1; i++ ) {
			if (a[i] > x) {
				x += (a[i] - x + 1) / 2;
				
			}
		}
		cout << x << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
