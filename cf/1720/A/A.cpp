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
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		long long x = a * d;
		long long y = b * c;
		if (x > y) swap(x, y);
		if (x == y) {
			cout << 0 << endl;
		} else if (x == 0 || y % x == 0) {
			cout << 1 << endl;
		} else {
			cout << 2 << endl;
		}
	}
	return 0;
}
