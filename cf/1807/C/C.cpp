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
		string s;
		cin >> n >> s;
		set<char> a[2];
		for (int i = 0; i < n; i++) {
			a[i % 2].insert(s[i]);
		}
		bool b = true;
		for (char i = 'a'; i <= 'z'; i++) {
			int cnt = 0;
			for (int j = 0; j < 2; j++) {
				if (a[j].find(i) != a[j].end())cnt++;
			}
			if (cnt == 2) b = false;
		}
		if (b) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
