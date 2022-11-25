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

long long solve(long long x) {
	if (x == 0) return 0;
	long long root = floor(sqrt((long double) x));
	long long sq = root * root;
	long long left = (x - sq);
	left /= root;
	return (root - 1) * 3 + (left + 1);
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		long long l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}
