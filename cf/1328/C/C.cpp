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
		vector<string> v(2);
		int cur = 0;
		bool f = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				v[0] += '0';
				v[1] += '0';
			} else if (s[i] == '1') {
				if (!f) {
					v[0] += '1';
					v[1] += '0';
				} else {
					v[1] += '1';
					v[0] += '0';
				}
				f = true;
			} else {
				if (!f) {
					v[0] += '1';
					v[1] += '1';
				} else {
					v[0] += '0';
					v[1] += '2';
				}
			}
		}
		cout << v[0] << endl << v[1] << endl;
	}
	

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
