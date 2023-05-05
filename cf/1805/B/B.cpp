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
		vector<string> v(26);
		for (int i = 0; i < 26; i++) {
			string t = s;
			for (int j = n - 1; j >= 0; j--) {
				if (t[j] == ('a' + i)) {
					t.erase(t.begin() + j);
					string u = "";
					u += ('a' + i);
					u += t;
					t = u;
					break;
				}
			}
			v[i] = t;
		}
		sort(v.begin(), v.end());
		cout << v[0] << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
