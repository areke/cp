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
		long long n, a, b;
		cin >> n >> a >> b;
		vector<long long> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector<pair<long long, long long> > p(n);
		for (int i = 0; i < n; i++) {
			p[i] = {v[i], i};
		}

		vector<long long> res1;
		vector<long long> res2;
		sort(p.begin(), p.end());
		for (int i = n - 1; i >= 0; i--) {
			long long acnt = res1.size() + 1;
			long long bcnt = res2.size() + 1;
			if (acnt * a <= bcnt * b) {
				res1.push_back(p[i].second);
			} else {
				res2.push_back(p[i].second);
			}
		}
		cout << res1.size() << " ";
		for (int i = 0; i < res1.size(); i++) {
			cout << res1[i] + 1;
			if (i != res1.size() - 1) cout << " ";
		}
		cout << endl;

		cout << res2.size() << " ";
		for (int i = 0; i < res2.size(); i++) {
			cout << res2[i] + 1;
			if (i != res2.size() - 1) cout << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
