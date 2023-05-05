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
	int n;
	cin >> n;
	vector<long long> v(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> v[i];
	}
	vector<long long> l(n - 1, 0);
	vector<long long> r(n - 1, 0);
	l[0] = 2 * v[0];
	l[1] = 2 * v[1] + l[0];
	for (int i = 2; i < n - 1; i++) {
		l[i] = 2 * v[i] + l[i - 2];
		if (i > 2) {
			l[i] = min(l[i], 2 * (v[i] + v[i - 1]) + l[i - 3]);
		}
	}

	r[n - 2] = 2 * v[n - 2];
	r[n - 3] = 2 * v[n - 3] + r[n - 2];
	for (int i = n - 4; i >= 0; i--) {
		r[i] = 2 * v[i] + min(r[i + 1], r[i + 2]);
		if (i < n - 4) {
			r[i] = min(r[i], 2 * (v[i] + v[i + 1]) + min(r[i + 3], r[i + 2]));
		}
	}
	for (int i = 0; i < n -1; i++) {
		cout << l[i] << " " ;
	}
	cout << endl;
	for (int i = 0; i < n -1; i++) {
		cout << r[i] << " " ;
	}
	cout << endl;
	cout << "HUH" << endl;
	int q;
	cin >> q;	
	for (int i = 0; i < q; i++) {
		long long k, x;
		cin >> k >> x;
		k--;
		long long left = 0;
		long long right = 0;
		
		if (k - 1 >= 0) left = l[k - 1];
		if (k - 2 >= 0) left = min(left, l[k - 2]);
		if (k - 3 >= 0) left = min(left, l[k - 3] + 2 * v[k - 1]);
		
		if (k + 1 < n - 1) right = r[k + 1];
		if (k + 2 < n - 1) right = min(right, r[k + 2]);
		if (k + 3 < n - 1) right = min(right, r[k + 3] + 2 * v[k + 1]);
		long long res = left + right + 2 * x;
		//cout << res << endl;
		if (k > 0 && k < n - 2) {
			cout << res << " " << l[k - 1] + r[k + 1] << endl;
			res = min(res, l[k - 1] + r[k + 1]);
		}
		cout << res << endl;
	}


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
