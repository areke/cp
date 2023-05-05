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

int sumD(long long x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		if (n % 2 == 0) {
			cout << n/2 << " " << n/2 << endl;
		} else {
			long long x = n / 2;
			long long y = n / 2;
			y++;
			int nc = 0;
			long long cx = x;

			while (cx && cx % 10 == 9) {
				nc++;
				cx /= 10;
			}
			if (nc == 0) {
				cout << x << " " << y << endl;
				continue;
			}
			long long cur = 9;
			for (int i = 1; i <= nc / 2; i++) {
				cur *= 10;
				x -= cur;
				y += cur;
			}
			if (nc % 2 == 1) {
				x -= 4;
				y += 4;
			}
			cout << x << " " << y << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
