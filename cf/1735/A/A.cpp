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
		long long n;
		cin >> n;
		long long l2 = (n - 3) / 3;
		long long res = abs(l2 - 1);
		cout << res << endl;
	}
	return 0;
}
