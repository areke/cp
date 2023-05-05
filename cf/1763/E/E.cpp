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
	int tests = 1;
	while (tests--) {
		long long p;
		cin >> p;
		long long orig = p;
		// 1 costs 2
		// 3 costs 3
		// 6 costs 4
		// 10 costs 5 etc
		vector<long long> v;
		long long cur = 1;
		long long s = 0;
		while (s <= p) {
			s += cur;
			v.push_back(s);
			cur++;
		}
		int ind = v.size() - 1;
		long long res = 0;
		while (p) {
			while (v[ind] > p) {
				ind--;
			}
			p -= v[ind];
			res += (ind + 2);
		}
		long long res2 = res * (res - 1) / 2;
		res2 -= orig;
		cout << res << " " << res2 << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
