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
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		set<int> s;
		for (int i = 1; i <= n; i++) {
			s.insert(i);
		}
		while (s.size() > 2) {
			vector<int> v(3);
			auto it = s.begin();
			for (int i = 0; i < 3; i++) {
				v[i] = *it;
				it++;
			}
			int a, b;
			cout << "? " << v[0] << " " << v[1] << endl;
			cin >> a;
			cout << "? " << v[1] << " " << v[2] << endl;
			cin >> b;
			int bad = -1;
			if (a > b) {
				bad = v[2];
			} else if (a < b) {
				bad = v[0];
			} else {
				bad = v[1];
			}
			s.erase(s.find(bad));
		}
		cout << "! ";
		for (int x : s) {
			cout << x << " ";
		}
		cout << endl;
		int ans;
		cin >> ans;
		if (ans == -1) {
			assert(0 == 1);
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
