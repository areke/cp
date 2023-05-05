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

// cnt can go up
// cnt can stay the same
// cnt can go down

// if count goes down ,we found a 1 bit. otherwise there were carries,

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		vector<long long> v(30, 0);
		long long cnt;
		cin >> cnt;
		long long set = 0;
		long long add = 0;
		int i = 0;
		for (int i = 0; i < 30; i++) {
			long long p = (long long) (1 << i);
			cout << "- " << p << endl;
			long long d;
			cin >> d;
			if (d < cnt) {
				v[29 - i] = 0;
			} else {
				v[29 - i] = 1;
				set++;
			}
			
			add += (long long) (1 << i);
			cnt = d;
			if (d == set) break;
		}
		long long res = 0;
		for (long long i = 0; i < 30; i++) {
			res += v[29 - i] * (1 << i);
		}
		cout << "! " << res + add << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
