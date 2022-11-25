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
		long long res = 0;
		vector<int> v(s.length(), 0);
		for (int i = 1; i <= n; i++) {
			for (int k = i; k <= n; k += i) {
				if (s[k - 1] == '1') break;
				if (!v[k - 1]) {
					res += i;
				}
				v[k - 1] = 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
