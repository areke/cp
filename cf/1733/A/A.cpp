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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; test++) {
		int n, k;
		cin >> n >> k;
		vector<vector<long long > > v(k);
		for (int i = 0; i < n; i++) {
			long long x;
			cin >> x;
			v[i % k].push_back(x);
		}
		for (int i = 0; i < k; i++) {
			sort(v[i].begin(), v[i].end());
		}
		int x = 0;
		vector<long long> res;
		while (x < n) {
			res.push_back(v[x % k][x / k]);
			x++;
		}
		long long ans = 0;
		for (int i = n - 1; i > n - k - 1; i--) {
			ans += res[i];
		}
		cout << ans << endl;
	}
	return 0;
}
