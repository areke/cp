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
		cin >> n;
		int s = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s % 2 == 0) {
			cout << 0 << endl;
			continue;
		}
		int cnt = 1e9;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2) {
				int cur = 0;
				while (a[i] % 2) {
					a[i] /= 2;
					cur++;
				}
				cnt = min(cur, cnt);
				
			} else {
				int cur = 0;
				while (a[i] % 2 == 0) {
					a[i] /= 2;
					cur++;
				}
				cnt = min(cur, cnt);
			}
		}
		cout << cnt << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
