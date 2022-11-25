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
	while (tests--) {
		// a * b / gcd(a, b)^2 <= 3
		long long n;
		cin >> n;
		long long res = n + 2 *(n / 2) + 2* (n / 3);
		cout << res << endl;
	}
	return 0;
}
