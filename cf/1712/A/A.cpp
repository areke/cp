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
		int n, k;
		cin >> n >> k;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			if (p[i] > k) cnt++;
		}
		cout << cnt << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
