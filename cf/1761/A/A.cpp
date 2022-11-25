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
		int n, a, b;
		cin >> n >> a >> b;
		if (a == n && b == n) {
			cout << "Yes" << endl;
			continue;
		}
		else if (a + b >= n) {
			cout << "No" << endl;
			continue;
		}
		else if (a + b + 1 == n) {
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;

	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
