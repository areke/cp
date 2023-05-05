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
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		m[v[i]] = i;
	}
	int res = 1;
	for (int i = 1; i < n; i++) {
		if (m[i] > m[i + 1]) {
			res++;
		}
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
