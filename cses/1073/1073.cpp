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
	multiset<long long> s;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		auto it = s.upper_bound(x);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(x);

	}
	cout << s.size() << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
