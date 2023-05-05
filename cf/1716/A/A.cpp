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
	for (int test = 1; test <= tests; test++) {
		long long n;
		cin >> n;
		if (n ==1) {
			cout << 2 << endl;
		} else if (n % 3 == 0) {
			cout << n / 3 << endl;
		} else if (n % 3 == 1) {
			cout << n / 3 + 1 << endl;
		} else {
			cout << n / 3 + 1 << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
