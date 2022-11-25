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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tests;

	map<long long, long long> m;
	while (tests--) {
		char c;
		long long x;
		cin >> c >> x;
		if (c == '+') {
			m[x] = x;
		} else {
			if (!m.count(x)) {
				cout << x << endl;
			} else {
				long long cur = m[x];
				while (m.count(cur)) {
					m[x] = cur + x;
					cur += x;
				}
				cout << m[x] << endl;
			}
		}
	}
	return 0;
}
