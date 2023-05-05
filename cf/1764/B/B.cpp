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

long long gcd(long long a, long long b) {
	if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		// 1, 5, 8, 16

		int n;
		cin >> n;
		vector<long long> a(n);
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long maxi = 0;
		long long g = a[0];
		for (int i = 0; i < n; i++) {
			g = gcd(a[i], g);
			maxi = max(maxi, a[i]);
		}
		cout << maxi / g << endl;


	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
