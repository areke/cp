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
	string s;
	cin >> s;
	vector<int> a(26, 0);
	for (int i = 0; i < s.length(); i++) {
		a[s[i] - 'A']++;
	}
	int cnt = 0;
	int ind = -1;
	for (int i = 0; i < 26; i++) {
		cnt += a[i] % 2;
		if (a[i] % 2) ind = i;
	}
	if (cnt > 1) {
		cout << "NO SOLUTION" << endl;
	} else {
		string res = "";
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j <  a[i] / 2; j++) {
				res += (char)('A' + i);
			}
		}
		if (ind != -1) res += (char)('A' + ind);
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j <  a[i] / 2; j++) {
				res += (char)('A' + i);
			}
		}
		cout << res << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
