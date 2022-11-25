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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		int n;
		cin >> n;
		long long x[100000];
		long long t[100000];
		long long maxi = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> t[i];
			maxi = max(maxi, t[i]);
		}
		long double minr = 1e9;
		long double maxl = -1e9;
		
		for (int i = 0; i < n; i++) {
			long long travel = maxi - t[i];
			long long right = x[i] + travel;
			long long left = x[i] - travel;
			minr = min((long double)right, minr);
			maxl = max((long double)left, maxl);
		}

		long double res = (maxl + minr) / 2.0;
		cout << fixed << setprecision(9) << res << endl;


	}
	return 0;
}
