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
		vector<int> v(n);
		set<int> s;
		set<int> r;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (s.find(x) == s.end()) {
				s.insert(x);
			} else {
				r.insert(x);
			}
		}
		int res = r.size();
		int left = s.size() - r.size();
		res += left / 2;
		if (left % 2 == 1) res++;
		cout << res << endl;
	}
	return 0;
}
