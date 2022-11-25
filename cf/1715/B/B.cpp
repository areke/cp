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
		long long n, k, b, s;
		cin >> n >> k >> b >> s;
		vector<long long> res(n, 0);
		res[0] = b * k;
		
		long long left = s - b * k;
		if (left < 0) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < n; i++) {
			long long x = min(left, k - 1);
			res[i] += x;
			left -= x;
		}
		if (left > 0) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << res[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
