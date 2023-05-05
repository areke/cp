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
	int tests = 1;
	while (tests--) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long s = 0;
		long long sub = 0;
		long long res = 0;
		vector<long long> rem(n + k, 0);
		for (int i = n - 1; i >= k; i--) {
			
			s -= sub;
			sub -= rem[i + k];
			long long last = max(a[i] - s, (long long) 0);
			long long m = (last / k);
			if (last % k) m++;
			s += m * k;
			sub += m;
			rem[i] = m;
			res += m;
		}
		//if (n == 6) cout << res << endl;
		long long left = 0;
		for (int i = k - 1; i >= 0; i--) {
			
			s -= sub;
			sub -= rem[i + k];
			long long last = max(a[i] - s,(long long) 0);
			long long m = (last / (i + 1));
			if (last % (i + 1)) m++;
			rem[i] = m;
			left = max(left, m);
		}
		res += left;
		cout << res << endl;





	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
