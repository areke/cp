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
		// 2
		// 3, and 4
		// if cnt <= 
		int n;
		cin >> n;
		map<int, int> m;
		bool can = true;
		vector<int> res(n);
		for (int i = 0; i < n / 2; i++) {
			int x;
			cin >> x;
			if (m.count(x))  {
				can = false;
			}
			m[x] = i;
		}
		priority_queue<int> pq;
		for (int i = n; i >= 1; i--) {
			if (m.count(i)) {
				res[2 * m[i] + 1] = i;
				pq.push(2 * m[i]);
			} else {
				if (pq.empty()) {
					can = false;
					break;
				}
				res[pq.top()] = i;
				pq.pop();
			}
		}
		if (!can) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i];
				if (i == res.size() - 1) cout << endl;
				else cout << " ";
			}
		}
	}
	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
