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

bool cycle(char c, map<char, char> & m, set<char> vis) {
	if (vis.find(c) != vis.end()) return true;
	if (!m.count(c)) return false;
	vis.insert(c);
	return cycle(m[c], m, vis);
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		int n;
		cin >> n;
		cin >> s;
		string res = "";
		map<char, char> m;
		set<char> used;
		for (int i = 0; i < s.length(); i++) {
			if (!m.count(s[i])) {
				for (char cur = 'a'; cur <= 'z'; cur++) {
					if (used.find(cur) != used.end()) continue;
					m[s[i]] = cur;
					set<char> vis;
					if (cycle(s[i], m, vis) && used.size() < 25) {
						m.erase(m.find(s[i]));
						continue;
					}
					used.insert(cur);
					break;
				}
			}
			res += m[s[i]];
		}
		cout << res << endl;

	}
	return 0;
}
