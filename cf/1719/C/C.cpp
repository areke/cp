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
		long long n, q;
		cin >> n >> q;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<long long> res(n, 0);
		long long cur = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[cur]) {
				cur = i;
			}
			res[cur]++;
		}
		for (int qq = 0; qq < q; qq++) {
			long long i, k;
			cin >> i >> k;
			i--;
			long long ans = res[i];
			if (i == cur) {
				ans += max((long long)0, k - (n - 1));
			}
			if (i == 0) {
				ans = min(k, ans);
			} else {
				ans = min(k - i + 1, ans);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
