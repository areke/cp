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
#include <unordered_map>
#include <unordered_set>
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

	int n, k;
	cin >> n >> k;
	vector<pair<long long, long long> > v;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), [](auto & a, auto & b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second;
	});
	multiset<long long> s;
	long long av = k;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		bool found = false;

		if (!s.empty()) {
			auto it = s.upper_bound(v[i].first);
			if (it != s.begin()) {
				it = --it;
				s.erase(it);
				found = true;
				s.insert(v[i].second);
				res++;
			}
			
		}
		if (!found && s.size() != k) {
			s.insert(v[i].second);
			res++;
		}
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
