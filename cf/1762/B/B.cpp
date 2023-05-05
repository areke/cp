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
		vector<pair<long long, long long> > v(n);
		for (int i = 0; i < n; i++ ) {
			long long x;
			cin >> x;
			v[i].first = x;
			v[i].second = i;
		}
		sort(v.begin(), v.end());
		vector<pair<long long, long long> > res;
		for (int i = 1; i < n; i++) {
			long long next = v[i].first % v[i - 1].first;
			if (next != 0) {
				next = v[i-1].first - next;
				res.push_back({v[i].second, next});
				v[i].first += next;
			}
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i].first + 1 << " " << res[i].second << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
