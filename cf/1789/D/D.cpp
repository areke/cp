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

void shift(int x, vector<int> & a) {
	vector<int> s(a.size(), 0);
	for (int i = 0; i < a.size(); i++) {
		if (i + x < a.size() && i + x >= 0) s[i] = a[i + x];
	}

	for (int i = 0; i < a.size(); i++) {
		a[i] = s[i] ^ a[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		string b;
		cin >> b;
		int ind = -1;
		vector<int> c(n);
		vector<int> d(n);
		for (int i = 0; i < n; i++) {
			if (b[i] == '1') {
				ind = i;
				break;
			}
		}
		if (ind == -1) {
			if (a == b) {
				cout << 0 << endl;
			} else {
				cout << -1 << endl;
			}
			continue;
		}
		for (int i = 0; i < n; i++) {
			c[i] = a[i] - '0';
			d[i] = b[i] - '0';
		}
		vector<int> res;
		int ind2 = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (c[i] == 1) {
				ind2 = i;
				break;
			}
		}
		if (ind2 == -1) {
			cout << -1 << endl;
			continue;
		}
		//cout << ind2 << " " << ind << " " << "HUH" << endl;
		if (ind2 < ind) {
			res.push_back(ind2 - ind);
			shift(ind2 - ind, c);
			for (int i = ind - 1; i >= 0; i--) {
				if (c[i] != d[i]) {
					res.push_back(ind - i);
					shift(ind - i, c);
				}
			}
		} else {
			for (int i = ind ; i>=0; i--) {
				if (c[i] != d[i]) {
					res.push_back(ind2 - i);
					shift(ind2 - i, c);
				}
			}
		}
		
		for (int i = ind + 1; i < n; i++) {
			if (c[i] != d[i]) {
				res.push_back(ind - i);
				shift(ind - i, c);
			}
		}
		
		cout << res.size() << endl;
		if (res.size()) {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i] << " ";
			}
			cout << endl;
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
