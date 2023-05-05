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
			cout << -1 << endl;
		} else {
			cout << n / 2 << " " << n / 2 << " " << 0 << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
