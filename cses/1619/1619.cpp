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
	vector<pair<long long, long long> > v(n);
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({a, 1});
		v.push_back({b, -1});
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i].second;
		res = max(res, cnt);
	}
	cout << res << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
