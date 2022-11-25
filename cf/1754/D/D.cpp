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
	long long n, x;
	cin >> n >> x;
	vector<long long> a(n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	set<int> vis;
	int maxi = 0;
	for (int i = 1; i <= x; i++) {
		if (m[i]) {
			m[i + 1] += m[i] / (i + 1);
			m[i] = m[i] % (i + 1);
		}
	}
	bool res = true;
	for (int i = 1; i < x; i++) {
		if (m[i]) res = false;
	}
	if (res) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
