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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long cnt = 0;
		long long res = 1;
		map<long long, long long> m;
		for (int i = 0; i < n; i++) {
			m[a[i]]++;
		}
		long long last = 0;
		for (auto it : m) {
			long long x = it.first;
			if (x <= cnt) {
				cnt += m[x];
				last = 0;
			} else if (x > cnt && last + m[x] + cnt - 1 >= x) {
				cnt += m[x] + last;
				res++;
				last = 0;
			} else {
				last += m[x];
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
