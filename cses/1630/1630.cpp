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
	vector<long long> v(n);
	long long s = 0;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> v[i] >> x;
		s += x;
	}
	sort(v.begin(), v.end());
	long long cur =0 ;
	for (int i = 0; i < v.size(); i++) {
		cur += v[i];
		s -= cur;
	}
	cout << s << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
