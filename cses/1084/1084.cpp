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
	int n, m;
	long long k;
	cin >> n >> m >> k;
	vector<long long> a(n), b(m);
	for (int i = 0; i< n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0;
	int ind = 0;
	for (int i = 0; i < a.size(); i++) {
		
		while (ind < b.size() && a[i] - k > b[ind]) ind++;
		if (a[i] + k < b[ind]) continue;
		if (ind < b.size()) {
			res++;
			ind++;
		}

		if (ind >= b.size()) break;
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
