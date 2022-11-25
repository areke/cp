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
	for (int test = 0; test < tests; test++) {
		string s;
		cin >> s;
		int n = s.length();
		vector<char> res(s.length());
		int cnt = 0;
		for (char d = '9'; d >= '0'; d--) {
			for (int i = s.length() - 1; i >= 0; i--) {
				if (s[i] == d) {
					if (i == n - 1 - cnt) res[n - 1 - cnt] = d;
					else res[n - 1 - cnt] = min('9', (char)(d + 1));
					cnt++;
				}
			}
			string t = "";
			for (int i = 0; i < s.length(); i++) {
				if (s[i] < d) t += s[i];
			}
			s = t;
		}
		sort(res.begin(), res.end());
		cout << string(res.begin(), res.end()) << endl;
	}
	return 0;
}
