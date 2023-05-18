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
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	set<long long> s;

	s.insert(0);
	for (int x : v) {
		set<long long> n = s;
		for (int j : s) {
			n.insert(x + j);
		}
		s = n;
	}
	cout << s.size() - 1 << endl;
	for (auto it = s.begin(); it != s.end(); it++) {
		if (*it == 0) continue;
		cout << *it << " ";
	}
	cout << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
