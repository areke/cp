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
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			long long tar = (3 * n + 3) / 2;
			int ind = 0;
			vector<pair<long long, long long> > v(n);

			for (int i = 0; i <= n /2; i++) {
				int cur = 1 + (i * 2);
				v[ind] = {cur, tar + ind - cur};
				ind++;
			}
			for (int i = 0; i < n / 2; i++) {
				int cur = 2 * n - i;
				v[ind] = {cur, tar + ind - cur};
				ind++;
			}
			for (int i = 0; i < n; i++) {
				cout << v[i].first << " " << v[i].second << endl;
			}
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
