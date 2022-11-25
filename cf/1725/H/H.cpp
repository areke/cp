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
		int n;
		cin >> n;
		vector<long long> a(n);
		int z = 0;
		int cnt = 0;
		string res = "";
		for (int i = 0; i < n; i++) {
			res += "0";
		}
		for (int i = 0; i < n; i++)	{
			cin >> a[i];
			if (a[i] % 3 == 0) z++;
			if (a[i] % 3 == 0 && cnt < n / 2) {
				res[i] = '1';
				cnt++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] % 3 != 0 && cnt < n / 2) {
				res[i] = '1';
				cnt++;
			}
		}
		if (z <= n / 2) {
			cout << 0 << endl;
		} else {
			cout << 2 << endl;
		}
		cout << res << endl;
	}
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
