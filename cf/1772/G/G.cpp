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

long long minRounds(long long d, long long ind, long long t, long long n) {
	if (ind >= t) return t;

	long long rounds = ((t - ind) / d + ((t - ind) % d != 0));
	long long ret = rounds * n;
	ret += t - (rounds * d);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	int testc = 0;
	while (tests--) {
		testc++;
		long long n, x, y;
		cin >> n >> x >> y;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		//if (tests >= 100 && testc != 865) continue; 
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] - i > x) {
				ind = i;
				break;
			}
		}
		/*
		if (testc == 865) {
			cout << n << " " << x << " " << y << " ";
			for (int i = 0; i < n; i++) cout << a[i] << " ";
			cout << endl;
		}*/
		if (ind == -1) {
			cout << y - x << endl;
			continue;
		}
		long long ans = 1e18;
		long long res = 0;
		// 1 2 3 5 8 9 20
		// 1 1 1 2 4 4 14
		//cout << ind << endl;
		while (ind < n) {
			if (x >= a[ind] - ind) {
				ind++;
				continue;
			}
			if (ind >= y - x) {
				res+= y - x;
				x = y;
				break;
			}
			if (2 * ind - n <= 0) {
				res = -1;
				break;
			}
			if (a[ind] >= y) {
				if (y - ind - x> 0) {
					//cout << ind << endl;
					long long rounds = (y - ind - x) / (2 * ind - n);
					if ((y - ind - x) % (2 * ind - n) != 0) rounds++;
					res += rounds * n;
					x += rounds * ( 2 * ind - n);
				}
				res += y - x;
				x = y;
				break;
			}
			long long t = a[ind] - ind - x;
			long long rounds = t / (2 * ind - n);
			if (t % (2 * ind - n) != 0) rounds++;
			res += rounds * n;
			x += (2 * ind - n) * rounds;
			//cout << ind << " " << x << " " <<res << " " << t << endl;
			ind++;
		}
		if (res != -1) {
			res += y - x;
		}
		cout << min(ans, res) << endl;


	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
