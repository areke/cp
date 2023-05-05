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
	cin >> tests;
	while (tests--) {
		int n;
		long long c;
		cin >> n >> c;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			v[i] = i + a[i] + 1;
		}
		for (int i = 0; i < n; i++) {
			v[n - i - 1] = min(v[n - i - 1], i + a[n - i - 1] + 1);
		}
		vector<pair<long long, int> > vv;
		map<int, int> m;
		map<int, int> r;
		for (int i = 0; i < n; i++) {
			vv.push_back({v[i], i});
		}
		sort(vv.begin(), vv.end());
		
		for (int i = 0; i < n; i++) {
			m[vv[i].second] = i;
			r[i] = vv[i].second;
			if (i > 0) {
				vv[i].first += vv[i - 1].first;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			long long cur = c - a[i] - (i + 1);
			int low = 0;
			int high = n - 1;
			
			if (cur < 0) {
				continue;
			}
			res = max(res, 1);
			int best = -1;
			while (low <= high) {
				int mid = (low + high) / 2;
				long long s = vv[mid].first;
				int ind = m[vv[mid].second];
				int cnt = 0;
				if (mid >= m[i]) {
					s -= v[i];
					cnt--;
				}
				cnt += mid + 1;
				
				if (s > cur) {
					high = mid - 1;
				} else {
					low = mid + 1;
					best = cnt;
					//cout << i << " " << mid << " " << cnt << " " << r[i] << endl;
				}
			}
			//cout << i << " " << best << endl;
			res = max(res, best + 1);
		}
		cout << res << endl;


	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
