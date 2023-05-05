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
		set<int> s;
		int m = -1;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(x);
			m = max(x, m);
		}
		int mex = -1;
		for (int i = 0;i <= n; i++) {
			if (s.find(i) == s.end()) {
				mex = i;
				break;
			}
		}
		if (mex > m) {
			cout <<  m + k + 1 << endl;
			continue;
		}
		while(k) {
			int next = (mex + m + 1) / 2;
			if (s.find(next) != s.end()) {
				break;
			}
			s.insert(next);
			while (s.find(mex) != s.end()) {
				mex++;
			}
			m = max(m, next);
			k--;
		}
		cout << s.size() << endl;
	}
 
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}