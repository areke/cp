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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		vector<pair<long long, long long> > a(n);
		for (int i = 0; i < n; i++) {
			long long x, y;
			cin >> x >> y;
			if (y > x) {
				swap(x, y);
			}
			a[i] = make_pair(x, y);
		}
		sort(a.begin(), a.end());
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += 2 * a[i].second;
		}
		res += 2 * a[n - 1].first;
		cout << res << endl;
	}
	
	return 0;
}
