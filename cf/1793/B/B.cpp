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
		long long x, y;
		cin >> x >> y;
		vector<long long> res;
		res.push_back(x);
		long long diff = x - y;
		for (int i = 1; i <= diff; i++) {
			res.push_back(x - i);
		}
		for (int i = 1; i < diff; i++) {
			res.push_back(y + i);
		}
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
