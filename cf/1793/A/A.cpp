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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long a, b;
		cin >> a >> b;
		long long n, m;
		cin >> n >> m;
		long long at = 0;
		long long res = 0;
		if (m * a <= (m + 1) * b) {
			at += (n / (m + 1)) * (m + 1);
			res += (n / (m + 1)) * m * a;
			n -= at;
		}
		//cout << at << " ? " << endl;
		if (a <= b) {
			res += n * a;
		} else {
			res += n * b;
		}
		cout << res << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
