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
	int n, a, b;
	cin >> n >> a >> b;
	
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<long long> p(n + 1);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + v[i];
	}
	multiset<long long> s;
	long long res = -1e18;
	for (int l = 0, r = 0; r <= n; r++) {
		while (r - l > b) {
			s.erase(s.find(p[l]));
			l++;
		}
		if (r >= a) {
			s.insert(p[r - a]);
			res = max(res, p[r] - *s.begin());
		}

	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
