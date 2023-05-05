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
	long long n, x;
	cin >> n >> x;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0, r = n - 1; i < r; i++, r--) {
		while (i < r && v[i] + v[r] > x) r--;
		if (i < r) cnt++; 
	}
	cout << n - cnt << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
