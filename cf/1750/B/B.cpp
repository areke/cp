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
		int n;
		cin >> n;
		string s;
		cin >> s;
		long long z = 0;
		long long o = 0;
		long long res = 0;
		char last = s[0];
		vector<string> v;
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				z++;
			} else {
				o++;
			}
			if (s[i] == last) {
				cur++;			
			} else {
				res = max(cur * cur, res);
				cur = 1;
			}
			last = s[i];
		}
		res = max(cur * cur, res);
		res = max(z * o, res);
		cout << res << endl;
	}
	return 0;
}
