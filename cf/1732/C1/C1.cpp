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
	while (tests--) {
		long long n, q;
		cin >> n >> q;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		long long best = -1;
		long long bestl = 0;
		long long bestr = 0;
		vector<pair<int, int> > qs;
		for (int qq = 0; qq < q; qq++) {
			int ll, rr;
			cin >> ll >> rr;
			qs.push_back(make_pair(ll, rr));
		}
		//  y + a >= (a ^ y)

		//  (y ^ x) <= y + x
		// y + a >= (y ^ a)


		// y + a == (a ^ y) iff (a & y) == 0
		vector<pair<long long, long long > > a;
		for (int i = 0; i < n; i++) {
			if (v[i] != 0) {
				a.push_back(make_pair(v[i], i));
			}
		}
		vector<long long> next(n);
		vector<long long> last(n);
		next[n - 1] = v.size() - 1;
		last[0] = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (v[i] == 0) {
				next[i] = next[i + 1];
			} else {
				next[i] = i;
			}
		}
		for (int i = 1; i < n; i++) {
			if (v[i] == 0) {
				last[i] = last[i - 1];
			} else {
				last[i] = last[i - 1] + 1;
			}
		}
		vector<long long> sumpref(v.size() + 1,0);
		vector<long long> xorpref(v.size() + 1, 0);
		for (int i = 1; i <= n; i++) {
			sumpref[i] = sumpref[i - 1] + v[i - 1];
			xorpref[i] = xorpref[i - 1] ^ v[i - 1];
		}
		
		//cout << res << endl;
		//cout << "???" << endl;
		for (int qq = 0; qq < qs.size(); qq++) {
			long long l = qs[qq].first - 1;
			long long r = qs[qq].second - 1;
			long long al = last[l];
			long long ar = last[r];
			long long res = sumpref[n] - xorpref[n];
			for (int i = 0; i < 40; i++) {
				if (al + i >= a.size()) break;
				int left = a[al + i].second;
				for (int j = 0; j < 40; j++) {
					if (ar < j + 1) break;
					int right = a[ar - j - 1].second;
					if (left > right) break;
					long long xorv = xorpref[right + 1] ^ xorpref[left];
					long long sumv = sumpref[right + 1] - sumpref[left];
					//cout << xorv << " " << sumv << " " << i << " " << n - j - 1 << endl;
		
					int realleft = left;
					if (v[left] == 0) realleft = min(next[left] - 1, n - 1);
					int realright = right;
					if (v[right] == 0) realright = min(next[right], n - 1);
					if (sumv - xorv == res && realright - realleft < r - l) {
						r = realright;
						l = realleft;
					}
				}
			}
			if (a.size() == 0) cout << 1 << " " << 1 << endl;
			else  cout << l + 1 << " " << r + 1 << endl;
		}
	}
	return 0;
}
