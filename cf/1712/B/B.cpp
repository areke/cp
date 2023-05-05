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
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			p[i] = i + 1;
		}
		for (int i = n - 1; i >= 0; i-=2) {
			if (i > 0) swap(p[i], p[i - 1]);
		}
		for (int i = 0; i < n; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
