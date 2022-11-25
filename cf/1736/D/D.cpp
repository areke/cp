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
#include <queue>
#include <list>
#include <cstring>
using namespace std;

//10011100




// 1 0
// 0 1
// 1 0
// 1 0
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int > diff;
		for (int i = 0; i < s.length() / 2; i++) {
			int l = 2 * i;
			int r = 2 * i + 1;
			if (s[l] == s[r]) continue;
			diff.push_back(l);
		}
		if (diff.size() % 2) {
			cout << -1 << endl;
			continue;
		}
		vector<int> m(diff.size());
		int cur = 0;
		for (int i = 0; i < diff.size(); i++) {
			if (s[diff[i]] - '0' == cur) {
				m[i] = diff[i];
			} else {
				m[i] = diff[i] + 1;
			}
			cur ^= 1;
		}
		cout << m.size() << " ";
		for (int i = 0; i < m.size(); i++) {
			cout << m[i] + 1 << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << 2 * i + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}
