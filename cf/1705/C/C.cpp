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
#include <unordered_map>
#include <unordered_set>
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
	for (int test = 1; test <= tests; test++) {
		int n, c, q;
		cin >> n >> c >> q;
		string s;
		cin >> s;
		vector<long long> l(c);

		vector<long long> r(c);
		vector<long long> len(c + 1, 0);
		len[0] = n;
		for (int i = 0; i < c; i++) {
			cin >> l[i] >> r[i];
			len[i + 1] = len[i] + r[i] - l[i] + 1;
		}
		for (int i = 0; i < q; i++) {
			long long k;
			cin >> k;
			int ind = 0;
			for (int j = c; j >= 0; j--) {
				if (len[j - 1] < k) {
					ind = j;
					break;
				}
			}
			for (int j = ind; j > 0; j--) {
				if (len[j - 1] < k) k = (k - len[j - 1] - 1) + l[j - 1];
			}
			cout << s[k - 1] << "\n";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
