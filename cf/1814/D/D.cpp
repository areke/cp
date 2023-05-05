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
		int n, k;
		cin >> n >> k;
		vector<long long> f(n), d(n);
		for (int i = 0; i < n; i++) {
			cin >> f[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		
		long long res = n;
		for (int i = 0; i < n; i++) {
			//cout << "HUH" << " " << i << endl;
			long long p = f[i] * d[i];
			long long h = p + k;
			long long l = max(0LL, p - k);
			vector<long long> pos;
			vector<long long> must;
			vector<long long> half;
			int eq = 0;
			long long curres = n;
			bool can = true;
			
			for (int j = 0; j < n; j++) {
				if (f[j] * d[j] == p) {
					must.push_back(p);
					eq++;
					continue;
				}
				int cnt = (h / f[j]) - max(0LL, (l - 1)) / f[j];
				if (cnt >= 2) {
					if (f[j] > k) {
						long long close = (p / f[j]) * f[j];
						long long ab = close + f[j];
						long long be = close - f[j];
						if (be < l) {
							assert(close < p);
							half.push_back(close);
							half.push_back(ab);
						} else {
							assert(ab > h && close > p);
							half.push_back(be);
							half.push_back(close);
						}
					} 
					if (f[j] * d[j] >= l && f[j] * d[j] <= h) {
						pos.push_back(f[j] * d[j]);
					}
				
				}
				else if (cnt == 1) {
					must.push_back((h / f[j]) * f[j]);
					if ((h / f[j]) * f[j] == d[j] * f[j]) eq++;
				}
				else can = false;
			}
			//cout << must.size() << " " << pos.size() << " " << eq << endl;
			
			if (!can) continue;

			sort(pos.begin(), pos.end());

			sort(must.begin(), must.end());
			sort(half.begin(), half.end());
			
			if (!must.empty() && must[must.size() - 1] - must[0] > k) continue;
			can = half.empty();
			vector<long long> musthalf = half;
			musthalf.insert(musthalf.end(), must.begin(), must.end());
			sort(musthalf.begin(), musthalf.end());
			for (int j = 0, m = 0; m < musthalf.size(); m++) {
				while (musthalf[m] - musthalf[j] > k) j++;
				if (m - j + 1 != half.size() / 2 + must.size()) continue;
				//if (n == 3000 && f[0] == 72) cout << half.size() << endl;
				can = true;
			}
			if (!can) continue;
			curres = n - eq;
			vector<long long> all(pos.begin(), pos.end());
			all.insert(all.end(), musthalf.begin(), musthalf.end());
			sort(all.begin(), all.end());
			for (int j = 0, m = 0, jj = 0, mm = 0, jjj = 0, mmm = 0; mmm < all.size(); mmm++) {
				while (all[mmm] - all[jjj] > k) jjj++;
				while (m < pos.size() && pos[m] <= all[mmm] ) m++;
				while (j < pos.size() && all[mmm] - pos[j] > k) j++;
				while (jj < half.size() && half[jj] < all[mmm] - k) jj++;
				while (mm < half.size() && half[mm] <= all[mmm]) mm++;
				if (mm - jj != half.size() / 2) continue;
				
				//cout << m << " " << j<< endl;
				if (!must.empty() && max(all[mmm], must[must.size() - 1]) - min(all[jjj], must[0]) > k) continue;
				//cout << "?" << endl;
				//cout << "?" << endl;
				curres = min(curres, n - (long long) (m - j + eq) );
			}
			//cout << i << " "<< curres << " " << pos[0] << " " << must.size() << endl;

			res = min(res, curres);
			
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
