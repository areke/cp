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
	long long x, n;
	cin >> x >> n;
	multiset<long long> s = {x};
	set<long long> p;
	p.insert(0);
	p.insert(x);
	for (int i = 0; i < n; i++) {
		long long y;
		cin >> y;
		auto r = p.lower_bound(y);
		auto l = --p.lower_bound(y);
		s.erase(s.find((*r) - (*l)));
		s.insert(y - (*l));
		s.insert((*r) - y);
		p.insert(y);
		cout << *(s.rbegin()) << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
