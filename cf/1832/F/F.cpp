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

vector<long double> e(1001, 0);

vector<bool> vis(1001, 0);

long double solve(int x) {
	if (vis[x]) return e[x];
	long double res = 3.0 / 4.0 * e[x - 2] + e[x - 3] + 1.5;
	e[x] = res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	for (int i = 0; i < 1000000; i++) {
		s.erase(i);
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
