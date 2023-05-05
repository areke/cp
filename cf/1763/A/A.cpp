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
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int inv = 1023;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < n; j++) {
				int p = (1 << i);
				if (v[j] & p) {
					int l = v[0] & p;
					v[0] |= p;
					v[j] &= (1023-p);
					v[j] |= l;
				}
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 1; j < n; j++) {
				int p = (1 << i);
				if (!(v[j] & p)) {
					int l = v[1] & p;
					v[1] &= (1023-p);
					v[j] &= (1023- p);
					v[j] |= l;
				}
			}
		}

		cout << v[0] - v[1] <<endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
