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
	while (tests--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<int> dmax(n,0);
		vector<int> dmin(n, 0);
		vector<int> cnts(n, 0);
		for (int i = 0; i < n; i++) {
			cnts[i] = n - (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
		}
		for (int i = 0; i < n; i++) {
			dmax[i] = b[i] - a[i];
		}
		int cur = b[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			dmax[i] = max(dmax[i], cur - a[i]);
			if (cnts[i] == n - i) {
				if (i >= 1) cur = b[i - 1];
			}
		}

		for (int i = 0; i < n; i++) {
			dmin[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];
		}
		for (int i = 0; i < n; i++) {
			cout << dmin[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << dmax[i] << " ";
		} cout << endl;


	}
	return 0;
}
