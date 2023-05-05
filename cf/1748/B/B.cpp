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
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		string s;
		cin >> s;
		set<char> ss;
		map<char, int> m;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < min((long long)100, n - i); j++) {
				ss.insert(s[i + j]);
				m[s[i + j]]++;
				bool b = true;
				for (char k = '0'; k <= '9'; k++) {
					if (m[k] > ss.size()) b = false;
				}
				if (b) res++;
			}
			ss.clear();
			m.clear();
		}
		cout << res << endl;
	}
	return 0;
}
