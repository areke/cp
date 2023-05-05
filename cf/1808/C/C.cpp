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
 
 
unsigned long long luck(unsigned long long n) {
	unsigned long long maxi = -1;
	unsigned long long mini = 1e7;
	while (n) {
		unsigned long long d = n% 10;
		maxi = max(maxi, d);
		mini = min(mini, d);
		n /= 10;
	}
	return maxi - mini;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	int otest = tests;
	while (tests--) {
		unsigned long long l, r;
		cin >> l >> r;
		unsigned long long mini = luck(l);
		unsigned long long res = l;
		for (int i = 0; i <= 9; i++) {
			for (int j = i; j <= 9; j++) {
				unsigned long long cur = l;
				unsigned long long s = 0;
				unsigned long long p = 1;
				bool can = true;
				while (cur) {
									if (i == 2 && j == 8) cout << cur << " " << s << endl;

					//if (i ==1 && j == 1) cout << cur << " " << s << endl;
					if (s + l > r) {
						can = false;
						break;
					}
					
					unsigned long long d = cur % 10;
					if (d >= i && d <= j) {
						p *= 10;
						cur /= 10;
						continue;
					}
					//cout << cur << " " << j << " " << i << " " << s << endl;
					if (d > j) {
						s += (10 + i - d) * p;
						cur += 10;
					} else {
						s += (i - d) * p;
					}
					
					if (s + l > r) {
						can = false;
						break;
					}
					p *= 10;
					cur /= 10;
				}
				if (can && j - i <= mini) {
					mini = j - i;
					res = l + s;
					cout << mini << " " << res << endl;
					//cout << mini << " " << res << " " << s << " " << i << " " << j <<  endl;
				}
			}
		}
		cout << res << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}