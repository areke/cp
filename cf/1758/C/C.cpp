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

// 5 2 3 4 1 
// 4 2 3 5 1

// 4 2 3 1
// 8 2 3 4 5 6 7 1
// 2 8 3 4 5 6 7 1


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n, x;
		cin >> n >> x;
		vector<int> res(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			res[i] = i;
		}
		res[1] = n;
		res[n] = 1;
		if (n % x == 0) {
			// n / x numbers are divisible by x
			// if x cannot be used there are n / x - 1
			if (x != n) {
				swap(res[1], res[x]);
				for (int i = 2; i < n; i++) {
					if (res[x] % i == 0 && res[i] % x == 0) {
						swap(res[i], res[x]);
						x = i;
						//cout << i << " "<< res[x] << " " << res[i] << endl;
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				cout << res[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
