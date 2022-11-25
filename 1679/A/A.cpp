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
		if (n % 2 == 1) {
			cout << -1 << endl;
		} else if (n == 2) {
			cout << -1 << endl;
		} else {
			long long maxi = n / 4;
			long long mini = maxi;
			for (int i = 0; i <= 3; i++) {
				if ((n - i * 4) % 6 == 0) {
					mini = min(mini, (n - i * 4) / 6 + i);
				}
			}
			cout << mini << " " << maxi << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
