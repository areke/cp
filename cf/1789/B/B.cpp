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
		string s;
		cin >> s;
		vector<int> v(n, 0);
		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - i - 1]) v[i] = 1;
		}
		vector<int> c;
		int cur = 0;
		for (int i = 0; i < n / 2; i++) {
			//cout << v[i] << " ";
			if (v[i]) {
				cur++;
			} else {
				if (cur) {
					c.push_back(cur);
					cur = 0;
				}
			}
		}
		if (cur) {
			c.push_back(cur);
		}
		if (c.size() > 1) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
