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
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	long long res = -1;
	long long maxi = -1;
	map<long long, int> m;
	for (int i = 1; i <= 25; i++) {
		cout << "? " << i << " " << i + 1 << endl;
		long long x;
		cin >> x;
		cout << "? " << i + 1 << " " << i << endl;
		long long y;
		cin >> y;
		m[x + y]++;
		if (x != y) {
			res = x + y;
			break;
		}
		if (x == -1) {
			res = i;
			break;
		}
	}
	if (res == -1) {
		for (auto it : m) {
			if (maxi < it.second && it.first != 1) {
				res = it.first;
				maxi = it.second;
			}
		}
	}
	cout << "! " << res << endl;


	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
