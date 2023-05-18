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
#include <numeric>
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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> r(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			v[i]--;
			r[v[i]] = i;
		}
		int g = -1;
		for (int i = 0; i < n; i++) {
			if (g == -1) g = abs(r[i] - i);
			else g = gcd(g, abs(r[i] - i));
		}
		cout << g << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
