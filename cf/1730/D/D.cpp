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
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		reverse(b.begin(), b.end());
		map<pair<int, int>, int> m;
		for (int i = 0; i < n; i++) {
			m[make_pair(min(a[i], b[i]), max(a[i], b[i]))]++;
		}
		bool res = true;
		bool mid = false;
		int odd = 0;
		for (auto it : m) {
			pair<int, int> p = it.first;
			if (it.second % 2) {
				if (p.first == p.second) odd++;
				else res = false;
			}
		}
		if (n % 2 && odd != 1) res= false;
		else if (n % 2 == 0 && odd) res = false;
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
