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
		int n, m;
		cin >> n >> m;
		int mini = 0;
		int maxi = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int cur = 0;
			vector<int> v;
			vector<int> z;
			for (int j = 0; j < m; j++) {
				if (s[j] == '1') {
					cur++;
				} else {
					v.push_back(cur);
					cur = 0;
				}
			}
			if (cur) v.push_back(cur);
			cur = 0;
			for (int j = 0; j < m - 1; j++) {
				if (s[j] == '0' || s[j + 1] == '0') {
					cur++;
					j++;
				}
			}
			cur = min(cur, m / 4);
			int tot = 0;
			int zeroes = 0;
			int ones = 0;
			int twos = 0;
			for (int x : v) {
				tot += x;
				twos += x / 2;
				ones += (x % 2);
			}
			for (int x : z) {
				zeroes += x / 2;
			}
			zeroes = min(zeroes, m / 4);
			twos = min(twos, m / 4);
			maxi += tot - (m/ 4 -cur);
			mini += twos + (tot - 2 * twos);
		}
		cout << mini << " " << maxi << endl;
	}
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}