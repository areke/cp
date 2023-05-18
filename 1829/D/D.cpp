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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	set<long long> good;
	for (long long i = 1; i <= 1e8; i *= 3) {
		good.insert(i);
	}
	for (int test = 1; test <= tests; test++) {
		long long n, m;
		cin >> n >> m;
		bool can = false;
		if (m > n) {
			cout <<"NO" << endl;
			continue;
		}
		if (n % m == 0 && good.find(n / m) != good.end()) {
			can = true;
		}
		while (m % 2 == 0) {	
			m /= 2;
			m *= 3;
			if (m > n) break;
			if (n % m == 0 && good.find(n / m) != good.end()) {
				can = true;
				break;
			}
		}
		if (can) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
