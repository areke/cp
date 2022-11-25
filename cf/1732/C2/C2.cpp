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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tests;
	while (tests--) {
		long long n, q;
		cin >> n >> q;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
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
		vector<long long> a;
		for (int i = 0; i < n; i++) {
			if (v[i]) {
				a.push_back(i);
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
			
			long long al = lower_bound(a.begin(), a.end(), l) - a.begin();
			long long ar = upper_bound(a.begin(), a.end(), r) - a.begin();
			ar--;
			long long res = sumpref[l + 1] - sumpref[l] - (xorpref[l + 1] ^ xorpref[l]);
			//cout << l << " " << r << " " << sumpref[r + 1] << " " << xorpref[r + 1] 
			//cout << res << endl;
			long long resl = l;
			long long resr = l;
			for (int i = 0; i < 32; i++) {
				if (i + al >= a.size()) break;
				long long left = a[al + i];
				for (int j = 0; j < 32; j++) {
					if (ar - j < 0) break;
					long long right = a[ar - j];
					long long curres = (sumpref[right + 1] - sumpref[left]) - (xorpref[right + 1] ^ xorpref[left]);
					if (left > right) continue;
					if (left < l) continue;
					if (right > r) continue;
					if (curres > res || (curres == res && right - left < resr - resl)) {
						res = curres;
						resl = left;
						resr = right;
					}
					
				}
			}
			//cout << resl + 1 << " " << resr + 1 << endl;



			cout << resl + 1 << " " << resr + 1 << endl;
		}
	}
	return 0;
}