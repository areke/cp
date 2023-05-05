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
		long long sub = 0;
		long long last = 0;
		long long maxi = 0;
		for (int i = 0; i < 32; i++) {
			sub += last;
			if ((1 << i) & n) {
				last = (1 << i);
				maxi = last;
			} else {
				last = 0;
			}
		}

		cout << n + maxi - sub - 1 << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
