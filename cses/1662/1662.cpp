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
	long long n, x;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> p(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
		p[i + 1] = ((p[i + 1]) % n + n) % n;
	}
	long long res = 0;
	map<long long, long long> m;
	for (int i = 0; i < n + 1; i++) {
		res += m[p[i]];
		m[p[i]]++;
	}
	cout << res << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
