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
	int n;
	cin >> n;
	vector<pair<long long, long long> > v;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({b, a});

	}
	long long res = 0;
	long long cur = -1;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= cur) {
			res++;
			cur = v[i].first;
		}
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
