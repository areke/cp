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
	vector<pair<int, int> > solve = {{0, 2}};

	for (int i = 0; i < n - 1; i++) {
		
		vector<int> ind = {0, 2, 1};
		vector<pair<int, int> > next;
		for (auto x : solve) {
			next.push_back({ind[x.first], ind[x.second]});
		}
		next.push_back({0, 2});
		ind = {1, 0, 2};
		for (auto x : solve) {
			next.push_back({ind[x.first], ind[x.second]});
		}
		solve = next;
	}
	cout << solve.size() << endl;
	for (auto x : solve) {
		cout << x.first + 1 << " " << x.second + 1 << endl;
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
