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
		int n, k, x;
		cin >> n >> k >> x;
		int kk = k;
		set<int> s;
		for (int i = 0; i <= n; i++) {
			s.insert(i);
		}
		vector<vector<int> > v;
		for (int i = 1; i <= n; i++) {
			
			if (s.find(i) != s.end() && s.find(x ^ i) != s.end()) {
				if (k > 1) {
					v.push_back({i, x ^ i});
					s.erase(s.find(i));
					s.erase(s.find(x ^ i));
					k--;
				}
			}
		}
		if (!s.empty()) {
			vector<int> last(s.begin(), s.end());
			v.push_back(last);
		}
		bool b = true;
		for (int i = 0; i < v.size(); i++) {
			vector<int> n;
			int val = 0;
			for (int j : v[i]) {
				if (j != 0) n.push_back(j);
				val ^= j;
			}
			v[i] = n;
			if (val != x) b = false;
		}
		if (v.size() != kk) b = false;
		if (b) {
			cout << "YES" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << v[i].size() << " ";
				for (int j = 0; j < v[i].size(); j++) {
					cout << v[i][j];
					if (j == v[i].size() - 1) {
						cout << endl;
					} else {
						cout << " ";
					}
				}
			}
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
