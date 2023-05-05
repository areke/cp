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
		if (n % 2 == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < n / 2; i++) {
				cout << 1 << " " << -1 << " ";
			}
			cout << endl;
		} else {
			if (n == 3) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
				int y = n / 2;
				int a = n / 2;
				int x = y * (1 - a) / a;
				for (int i = 0; i < y; i++) {
					cout << x << " " << y << " ";
				}
				cout << x << endl;
			}
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
