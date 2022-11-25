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
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> swaps;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != s[i - 1]) {
				swaps.push_back(i);
			}
		}
		int res = swaps.size();
		if (s[0] == '0') {
			cout << max(res - 1, 0) << endl;
		} else {
			cout << res << endl;
		}
	}
	return 0;
}
