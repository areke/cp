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
	for (int test = 0;  test < tests; test++) {
		long long n, x, y;
		cin >> n >> x >> y;
		if (x > y) swap(x, y);
		if (x != 0) {
			cout << -1 << endl;
			continue;
		}
		if (y == 0) {
			cout << -1 << endl;
			continue;
		}
		if ((n - 1) % y != 0) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n - 1; i++) {
			cout << (i / y) * y + 2;
			if (i == n - 2) cout << endl;
			cout << " ";
		}
	}
	return 0;
}
