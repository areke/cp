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
		int res = 0;
		int s = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 1) {
				cnt++;
			} else {
				if (cnt == 0) continue;
				if (cnt % 2 == 0) {
					s += (cnt - 2) / 2;
					cnt = 2;
				} else {
					s += cnt / 2;
					cnt = 1;
				}
			}
			//cout << i << " " << cnt << " " << s << endl;
			res = max(res, cnt + s);
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
