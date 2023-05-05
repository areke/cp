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
		if (n % 2 == 0) {
			for (int i = 1; i <= n / 2; i++) {
				cout << (n - i) << " " << (n + i) << " ";
			}
			cout << endl;
		} else {
			if (n == 3) {
				cout << "6 8 11" << endl;
			} else {
				long long t = (n + 2) * (n + 2);
				vector<long long> res;
				res.push_back(t / n);
				for (int i = 1; i <= n / 2; i++) {
					res.push_back(t / n - i);
					res.push_back(t / n + i);
				}
				sort(res.begin(), res.end());
				
				res[n - 1]+= 3;
				res[n - 2] += 1;
				for (int i = 0; i < n; i++) {
					cout << res[i] << " ";
				}
				cout << endl;
			}
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
