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

int best(int x) {
	int res = 0;
	while (x) {
		x /= 2;
		res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		string s;
		cin >> s;
		int ret = 1e9;
		for (char c = 'a'; c <= 'z'; c++) {
			int cnt = 0;
			int res = 0;
			for (int i = 0; i < s.length(); i++) {
				if (s[i] != c) {
					cnt++;
				} else {
					res = max(res, best(cnt));
					cnt = 0;
				}
			}
			res = max(res, best(cnt));
			ret = min(ret, res);
		}
		cout << ret << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
