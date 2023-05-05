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
		if (n % 2) {
			for (int i = 0; i < n; i++) {
				cout << n << " ";
			}
			cout << endl;
		} else {
			cout << 1 << " " << 3 << " ";
			for (int i = 0; i < n - 2; i++) {
				cout << 2 << " ";
			}
			cout << endl;

			// 2 
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
