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
		long long n, k;
		cin >> n >> k;
		vector<long long> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<vector<pair<long long, long long> > > jmp(20, vector<pair<long long, long long> >(n, {0, 0}));

		for (int i = 0; i < n; i++) {
			if (b[i] == 1) {
				long long cur = a[i];
				int len = 1;
				for (int j = 1; j <= n; j++) {
					if (b[(i + j) % n] == 1) {
						len = j;
						break;
					}
					if (cur + a[(i + j) % n] >= k) {
						long long left = cur + a[(i + j) % n] - k;
						cur = k + 2 * left;
						len = j + 1;
						break;
					}
					cur += a[(i + j) % n];
				}
				jmp[0][i] = {len, cur};
			} else {
				jmp[0][i] = {1, 2 * a[i]}; 
			}
		}

		vector<long long> pref(2 * n + 1, 0);
		for (int i = 0; i < 2 * n; i++) {
			pref[i + 1] = pref[i] + a[i % n];
		}
		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < n; j++) {
				int nxt = (jmp[i - 1][j].first + j) % n;
				pair<long long, long long> cur = jmp[i - 1][j];
				jmp[i][j] = {cur.first + jmp[i - 1][nxt].first, cur.second + jmp[i - 1][nxt].second };
			}
		}
		vector<long long> res(n, 0);
		for (int i = 0; i < n; i++) {
			int cur = i;
			int len = n;
			for (int j = 19; j >= 0; j--) {
				if (jmp[j][cur].first > len) {
					continue;
				}
				len -= jmp[j][cur].first;
				res[i] += jmp[j][cur].second;
				cur = (cur + jmp[j][cur].first) % n;
			}
			res[i] += pref[cur + len] - pref[cur];
		}
		for (int i = 0; i < n; i++) {
			cout << res[i] << " \n"[i == n - 1];
		}

	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
