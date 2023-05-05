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
		string s;
		cin >> s;
		int cnt = 0;
		vector<long long> res(n - 1);
		res[0] = 1;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == s[i - 1]) {
				cnt++;
				res[i] = res[i - 1];
			} else {
				cnt = 0;
				res[i] = i + 1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
