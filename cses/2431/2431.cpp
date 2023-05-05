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
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long k;
		cin >> k;
		long long d = 1;
		long long cnt = 1;
		long long l = k;
		long long cur = 0;
		while (9 * d * cnt <= l) {
			l -= 9 * d * cnt;
			
			cnt++;
			cur += 9 * d;
			d *= 10;
		}
		
		cur += l / cnt;
		l = l % cnt;
		
		if (l == 0) {
			cout << cur % 10 << endl;
			continue;
		}
		cur++;
		vector<int> v;
		while (cur) {
			v.push_back(cur % 10);
			cur /= 10;
		}
		reverse(v.begin(), v.end());
		cout << v[l - 1] << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
