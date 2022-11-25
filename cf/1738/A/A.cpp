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

long long solve(vector<long long> a, vector<long long> b) {
	int p = 0;
	long long res = 0;
	for (int i = 0; i < a.size(); i++) {
		if (i < b.size()) {
			res += b[b.size() - i - 1];
			if (i + 1 < a.size()) res += a[a.size() - i - 1];
		}
	}
	return res;
}
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		vector<long long> c;
		vector<long long> d;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += b[i];
			if (a[i]) c.push_back(b[i]);
			else d.push_back(b[i]);
		}
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		res += max(solve(c, d), solve(d, c));
		cout << res << endl;
	}
	return 0;
}
