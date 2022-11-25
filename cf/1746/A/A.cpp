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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		bool found = false;
		bool zero = false;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i]) found = true;
			if (!a[i]) zero = false;
		}
		if (!found || (a.size() == 2 && zero)) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
