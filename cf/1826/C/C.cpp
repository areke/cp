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

long long MAXI = 1000000 + 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		long long n, m;
		cin >> n >> m;
		// no if number less than m divides n
		string res = "YES";
		for (int i = 1; i <= sqrt(n) + 1; i++) {
			if (n % i == 0) {
				int a = i;
				int b = n / i;
				if ((a != 1 && a <= m) || (b != 1 && b <=m)) {
					res = "NO";
					break;
				}
			}
		}
		cout << res << "\n";

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
