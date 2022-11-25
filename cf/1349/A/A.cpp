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

long long gcd(long long a, long long b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	long long g = gcd(v[0], v[1]);
	long long l = v[0] / g * v[1];
	long long l2 = v[0] / g * v[1];
	for (int i = 2; i < n; i++) {
		g = gcd(l, v[i]);
		l2 = l;
		l = g;
	}
	cout << l2 << endl;
	return 0;
}
