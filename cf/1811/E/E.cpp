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
		long long cur = 0;
		vector<long long> res;
		while (n) {
			res.push_back(n % 9);
			n /= 9;
		}
		reverse(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			if (res[i] >= 4) res[i]++;
		}
		for (int i = 0; i < res.size(); i++) {
			cout << res[i];
		}
		cout << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
