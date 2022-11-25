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

long long solve(long long x, vector<long long> & l, vector<long long> & r) {
	vector<pair<long long, int> > v;
	for (int i = 0; i < l.size(); i++) {
		if (r[i] - l[i] >= x) {
			v.push_back({0, 0});
			v.push_back({x, 1});
			continue;
		}
		long long left = l[i] % x;
		long long right = r[i] % x;
		if (right < left) {
			v.push_back({left, 0});
			v.push_back({x, 1});
			v.push_back({0, 0});
			v.push_back({right + 1, 1});
		} else {
			v.push_back({left, 0});
			v.push_back({right + 1, 1});
		}
	}
	sort(v.begin(), v.end());
	long long res = 0;
	long long cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		//cout << x << " " << i << " " << v[i].first << " " << v[i].second << endl;
		if (v[i].second == 0) {
			cnt++;
		} else {
			cnt--;
		}
		if (i == v.size() - 1 || v[i + 1].first > v[i].first) {
			res = max(cnt, res);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests = 1;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> l(n);
		vector<long long> r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}
		vector<long long> res(30);
		for (long long i = 0; i < 30; i++) {
			res[i] = solve(1 << i, l, r);
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			long long w;
			cin >> w;
			long long ans = 0;
			for (long long j = 0; j < 30; j++) {
				if ((1 << j) & w) {
					ans = res[j];
					break;
				}
			}
			cout << ans << endl;
		}
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
