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
		long long n, q;
		cin >> n >> q;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(n);
		string res = "";
		for (int i = 0; i < n; i++) {
			res += "0";
		}
		int iq = 0;
		priority_queue<long long> pq;
		for (int i = n - 1; i >= 0; i--) {
			if (iq >= a[i]) {
				res[i] = '1';
			} else {
				if (iq < q) {
					iq++;
					res[i] = '1';
				}
			}
		}
		cout << res << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
