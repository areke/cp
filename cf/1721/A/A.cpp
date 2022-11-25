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

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		string t;
		cin >> s;
		cin >> t;
		set<char> ss;
		for (int i = 0 ; i < s.length(); i++) {
			ss.insert(s[i]);
		}
		for (int i = 0 ; i < t.length(); i++) {
			ss.insert(t[i]);
		}
		cout << ss.size() - 1 << endl;
	}
	return 0;
}
