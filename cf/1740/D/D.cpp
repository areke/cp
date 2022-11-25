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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n, m, k;
		cin >> n >> m >> k;
		long long limit = n * m - 2;
		long long cur = k;
		set<long long> s;
		bool b = true;
		for (int i = 0; i < k; i++) {
			long long x;
			cin >> x;
			s.insert(x);
			if (s.size() == limit) {
				b = false;
			}
			while (s.find(cur) != s.end()) {
				s.erase(s.find(cur));
				cur--;
			}
			//cout << x << " " << s.size() << endl;
			//cout << s.size() << endl;
		}
		if (b) {
			cout << "YA" << endl;
		} else {
			cout << "TIDAK" << endl;
		}

	}
	return 0;
}
