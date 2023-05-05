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
		cin >> n;
		vector<int> v;
		bool can = true;
		while (n != 1) {
			if (n % 2 == 0) {
				can = false;
				break;
			}
			if (((n + 1) / 2) % 2) {
				n = (n + 1) / 2;
				v.push_back(1);
			} else {
				v.push_back(2);
				n = (n - 1) / 2;
			}
		}
		reverse(v.begin(), v.end());
		if (can) {
			cout << v.size() << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i == v.size() - 1) cout << endl;
				else cout << " ";
			}
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
